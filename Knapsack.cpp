#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int max_value){
    int n = weight.size();
    int knapsack[n+1][max_value+1];
    for(int i=0; i<n+1; i++)
        knapsack[i][0] = 0;
    for(int i=0; i<max_value+1; i++)
        knapsack[0][i] = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=max_value; j++)
            if(j < weight[i-1])
                knapsack[i][j] = knapsack[i-1][j];
            else
                knapsack[i][j] = max(knapsack[i-1][j], (knapsack[i-1][j-weight[i-1]] + value[i-1]));
    return knapsack[n][max_value];
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

/*
3
10 20 30 
60 100 120 
50
*/