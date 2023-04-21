#include<stdio.h>
int main()
{
    int N,i,t1=0,t2=1,nextt;

    printf("Enter number\n");
    scanf("%d",&N);

    for(i=1;i<=N;i++)
    {
    printf("%d\n",t1);
    nextt=t1+t2;
    t1=t2;
    t2=nextt;
    }

}