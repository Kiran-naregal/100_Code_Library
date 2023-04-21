#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int gcd = arr[0];
    for(int i=1; i<n; i++)
        gcd = __gcd(gcd, arr[i]);
    cout<<gcd<<endl;
    if(gcd == 1 || gcd == 2)
        cout<<1;
    else{
        int first = 1, second = 1, temp;
        for(int i=3; i<=gcd; i++){
            temp = first + second;
            first = second;
            second = temp;
        }
        cout<<second<<endl;
    }
    return 0;
}