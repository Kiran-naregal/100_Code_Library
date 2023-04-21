#include<bits/stdc++.h>
using namespace std;

int main(){
    string num;
    cin>>num;
    long n;
    cin>>n;
    long ans = 0;
    for(size_t i=0; i<num.length(); i++){
        ans = (ans * 10 + num[i] - '0') % n;
    }
    cout<<ans;
    return 0;
}