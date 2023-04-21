#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    int cost;
    struct node *next;
};

struct node *x[1001]= {NULL},*y[1001];

void insert(int a,int b,int cost)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=NULL;
    ptr->data=b;
    ptr->cost=cost;
    if(x[a]==NULL)
    {
        x[a]=ptr;
        y[a]=ptr;
    }
    else
    {
        y[a]->next=ptr;
        y[a]=ptr;
    }
}

int ans=99999999;
static int dp[1001][1111];

void aa(int start)
{
    static int a[10000001],b[10000001],i,j,k,l;
    int start1=1,end1=1;

    struct node *ptr;
    a[1]=start;
    b[1]=0;

    while(start1<=end1)
    {
        i=a[start1];
        j=b[start1];
        start1++;
        ptr=x[i];
        //dp[i][j]=1;
        while(ptr!=NULL)
        {
            if(dp[ptr->data][j|ptr->cost]==0)
            {
                end1++;
                dp[ptr->data][j|ptr->cost]=1;
                a[end1]=ptr->data;
                b[end1]=j|ptr->cost;
            }
            ptr=ptr->next;
        }
    }
}

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m,n,i,j,k,l,start,end;
    scanf("%d %d",&n,&m);

    for(i=1; i<=m; i++)
    {
        scanf("%d %d %d",&k,&l,&j);
        insert(k,l,j);
        insert(l,k,j);
    }
    scanf("%d %d",&start,&end);

    aa(start);
    for(i=0; i<1111; i++)
    {
        if(dp[end][i])
        {
            printf("%d",i);
            break;
        }
    }
    if(i==1111)
        printf("-1");
    return 0;
}