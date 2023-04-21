#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n;
    int arr[n], single = 0, unique_count = 0;
    cin>>k;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    sort(arr, arr+n);
     for(int i=0; i<n; i++){
        int j=1;
        while(arr[i] == arr[i+1]){
            j++;
            i++;
        }
        if(j==1)
            single++;
        else
            unique_count++;
    }
    if(single + unique_count == 2*k){
        cout<<"YES1"<<endl;
        return;
    }
    int extra = (2*k)-(single + unique_count);
    for(int i=0; i<unique_count; i++){
        if(extra==0)
            break;
        else
            extra--;
    }
    if(extra == 0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
2
6 2
1 4 4 6 2 1
4 2
1 1 1 1

YES
NO
*/
