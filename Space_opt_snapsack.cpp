#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int max_wt){
    int n = wt.size();
    vector<int> dp(max_wt+1);
    for(int i=0; i<n; i++){
        for(int j=max_wt; j>=wt[i]; j--){
            dp[j] = max(dp[j], val[i]+dp[j-wt[i]]);
        }
    }
    return dp[max_wt];
}


int main(){
    int n, max;
    cin>>n;
    vector<int> weight(n), value(n);
    for(int i=0; i<n; i++)
        cin>>weight[i];
    for(int i=0; i<n; i++)
        cin>>value[i];
    cin>>max;
    cout<<knapsack(weight, value, max);
    return 0;
}