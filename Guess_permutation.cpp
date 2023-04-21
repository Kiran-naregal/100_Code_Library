#include <bits/stdc++.h>
using namespace std;

void findPermutation()
{
    int N;
    cin>>N;
    N = N+1;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin>>A[i];
	int lasEle = 0;

	int perm[N];
	perm[0] = 0;

	for (int i = 1; i < N; i++) {

		lasEle += A[i - 1];

		perm[i] = lasEle;
	}

	int sm = *min_element(perm, perm + N);

	unordered_set<int> st;
	int mx = 0;

	for (int i = 0; i < N; i++) {

		perm[i] += (-sm) + 1;

		mx = max(mx, perm[i]);

		st.insert(perm[i]);
	}

	if (mx == N and st.size() == N) {
		for (int i = 0; i < N; i++) {
			cout << perm[i] << " ";
		}
	}

	else {
		cout << -1 << " ";
	}
}

int main()
{
	int T;
    cin>>T;
    while(T>0){
	    findPermutation();
        T--;
    }
	return 0;
}
