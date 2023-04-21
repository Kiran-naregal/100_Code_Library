#include <bits/stdc++.h>
using namespace std;

int minTrials(int n, int k)
{
	int dp[n + 1] = { 0 }, m;
	for (m = 0; dp[n] < k; m++) {
		for (int x = n; x > 0; x--) {
			dp[x] += 1 + dp[x - 1];
		}
	}
	return m;
}

int main()
{
int n = 2, k = 36;
cout<<"Minimum number of trials "
			"in worst case with "
		<< n << " eggs and " << k << " floors is ";
	cout << minTrials(2, 36);
	return 0;
}