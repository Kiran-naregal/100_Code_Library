#include<iostream>
#include<string>

using namespace std;

int main(){
    int n, k, arr[2000000], i, sum=0, ele, one, zero, j, out[2000000], flag = 0;
	scanf("%d %d", &n, &k);
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
        if(arr[i]==1)
            one++;
        else
            zero++;
    }
    if(one == 0 || zero == 0 || n == k){
        cout<<0<<endl;
        for(i=0;i<(k-1);i++)
		    printf("%d %d\n", i+1,i+1);
        if(k!=n)
		    printf("%d %d", i+1,n);
        return 0;
    }
    j = n-1;
    out[k-1] = j;
    for(i=0; i<(k-2); i++){
        ele = arr[j];
        j--;
        while(arr[j] == ele && j>-1)
            j--;
        out[k-(i+2)] = j;
    }
    for(i=j;i>-1; i++){
        if(arr[i] == 1){
            cout<<1<<endl;
            flag = 1;
        }
    }
    return 0;
}