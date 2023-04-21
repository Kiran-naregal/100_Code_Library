#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, sum;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cin>>sum;
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
    for(int i=0; i<=n; i++)
        dp[i][0] = true;
    for(int i=1; i<=sum; i++)
        dp[0][i] = false;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++)
            if(j < arr[i-1])
                dp[i][j] =  dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++)
            cout<<dp[i][j];
        cout<<endl;
    }
    cout<<dp[n][sum];
    return 0;
}