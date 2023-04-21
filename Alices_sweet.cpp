#include<cstring>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int minimumValue (int N, vector<int> A, vector<int> B, vector<int> C) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    int i, j, k, min_ele, min_results=INT_MAX, cur_res;
    i=j=k=0;
    while (i<N && j<N && k<N){
        min_ele = min(min(A[i],B[j]),C[k]);
        cur_res = abs(A[i]-B[j])+abs(B[j]-C[k])+abs(C[k]-A[i]);
        if(cur_res< min_results)
            min_results = cur_res;
        if(A[i]==min_ele)
            i++;
        else if(B[j]==min_ele)
            j++;
        else
            k++;
    }
    
    return min_results;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i_A = 0; i_A < N; i_A++)
    {
    	cin >> A[i_A];
    }
    vector<int> B(N);
    for(int i_B = 0; i_B < N; i_B++)
    {
    	cin >> B[i_B];
    }
    vector<int> C(N);
    for(int i_C = 0; i_C < N; i_C++)
    {
    	cin >> C[i_C];
    }

    int out_;
    out_ = minimumValue(N, A, B, C);
    cout << out_;
}

/*input
3
4 2 5
3 2 1
5 5 5
output 4
Algo
find min and decrement it
time complexity n log n
*/