#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> v){
	int currSum = 0;
	int maxSum = INT_MIN;
	for (int i = 0;
		i < (int)v.size(); i++) {
		currSum += v[i];
		if (currSum > maxSum) {
			maxSum = currSum;
		}

		if (currSum < 0) {
			currSum = 0;
		}
	}
	return maxSum;
}

void maxSubmatrixSum(vector<vector<int> > A){
	int r = A.size();
	int c = A[0].size();
	int** prefix = new int*[r];
	for (int i = 0; i < r; i++) {

		prefix[i] = new int;
		for (int j = 0; j < c; j++) {
			prefix[i][j] = 0;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (j == 0)
				prefix[i][j] = A[i][j];
			else
				prefix[i][j] = A[i][j]
							+ prefix[i][j - 1];
		}
	}
	int maxSum = INT_MIN;
    int min_j, max_j;
	for (int i = 0; i < c; i++) {
		for (int j = i; j < c; j++) {
			vector<int> v;
			for (int k = 0; k < r; k++) {
				int el = 0;
				if (i == 0)
					el = prefix[k][j];
				else
					el = prefix[k][j]
						- prefix[k][i - 1];
				v.push_back(el);
			}
            int temp = kadane(v);
			if(temp > maxSum){
                maxSum = temp;
                min_j = i;
                max_j = j;
            }
            // cout<<i<<" "<<j<<" "<<temp<<endl;
		}
	}
	cout << maxSum <<endl;
}

int main()
{
	vector<vector<int>> matrix;
	int n, m, temp;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		vector<int> row;
		for(int j=0; j<m; j++){
			cin>>temp;
			row.push_back(temp);
		}
		matrix.push_back(row);
	}
	maxSubmatrixSum(matrix);
	return 0;
}
