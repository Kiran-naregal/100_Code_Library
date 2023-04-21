#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<long> arr(n);
        for(long i=0; i<n; i++)
            cin>>arr[i];
        long count=0;
        bool flag = false;
        for(long i=0; i < (n-1); i++){
            long temp=0;
            for(long j=i+1; j<n; j++){
                if(arr[i] > arr[j] && j>i){
                    count++;
                    temp++;
                }
                if(arr[i] == arr[j]){
                    count -= temp;
                    break;
                }
            }
            if(count >= n){
                flag = true;
                break;
            }
        }
        if(flag)
            cout<<count<<endl<<"YES"<<endl;
        else
            cout<<count<<endl<<"NO"<<endl;
    }
    return 0;
}