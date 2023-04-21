#include <iostream>
using namespace std;

int minDifference(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	int y = sum / 2 + 1;
	bool dp[y], dd[y];

	for (int i = 0; i < y; i++) {
		dp[i] = dd[i] = false;
	}
	dp[0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j + arr[i] < y; j++) {
			if (dp[j])
				dd[j + arr[i]] = true;
		}
		for (int j = 0; j < y; j++) {
			if (dd[j])
				dp[j] = true;
			dd[j] = false;
		}
	}
	for (int i = y - 1; i >= 0; i--) {
		if (dp[i])
			return (sum - 2 * i);
	}
}
int main()
{

	int arr[] = { 1, 6, 11, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The Minimum difference of 2 sets is "
		<< minDifference(arr, n) << '\n';
	return 0;
}
