#include<iostream>

using namespace std;

int main(){
    int T, n, arr[100000], l, r=0, sum, count, i, j;
    cin>>T;
    if(T<1 && T>10)
        exit(0);
    for(i=0; i<T; i++){
        cin>>n;
        if(n<1 && n>100000)
            exit(0);
        for(j=0; j<n; j++)
            cin>>arr[j];
        sum = 0;
        r=0;
        count=0;
        for(l=0; l<n ;l++){
            while (r<n && (sum+arr[r])==(sum ^ arr[r])){
                sum +=arr[r];
                r++;
            }
            count +=r-l;
            if(r==l)
                r++;
            else
                sum -= arr[l];
        }
        cout<<count<<endl;
    }
    return 0;
}