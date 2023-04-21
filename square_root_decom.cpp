#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, l, r, queries;
    cin>>n;
    vector<int> arr(n);
    int root = sqrtl(n) + 1;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<int> ans(root);
    for(int i=0; i<n; i++){
        ans[i/root] += arr[i];
    }
    cin>>queries;
    while(queries--){
        cin>>l>>r;
        l--; r--;
        int sum = 0;
        for(int i=l; i<n; ){
            if(i%root == 0 && i+root-1 <=r){
                sum += ans[i/root];
                i += root;
            }
            else{
                sum += arr[i];
                i++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

/*
in
9
1 5 -2 6 8 -7 2 1 11
2
1 6
2 7

out
11
12

*/