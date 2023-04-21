#include <bits/stdc++.h>  
using namespace std;  
  
int coins[] = { 10, 25, 5 };
int dp[1000] = { 0 };
int minCoins(int N, int M)
{  
  
    for (int i = 0; i <= N; i++)  
        dp[i] = INT_MAX;
  
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {  
        for (int j = 0; j < M; j++) {  
            if (coins[j] <= i) {  
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);  
            }  
        }  
    }  
    return dp[N];  
}  
  
int main()  
{  
  
    int sum = 30;
    int total_coins = 3;
    cout << "Minimum coins needed are " << minCoins(sum, total_coins);  
}  