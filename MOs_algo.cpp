#include<bits/stdc++.h>
using namespace std;
int rootN;
struct Query{
    int l, r;//, index;
};
Query q[1000];

bool compare(Query q1, Query q2){
    if(q1.l/rootN == q2.l/rootN){
        return q1.r > q2.r;
    }
    return q1.l/rootN < q2.l/rootN;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    rootN = sqrtl(n);
    int queries, l,r;
    cin>>queries;
    for(int i=0; i<queries; i++){
        cin>>l>>r;
        q[i].l = l;
        q[i].r = r;
    }
    sort(q, q+queries, compare);
    // for(int i=0; i<queries; i++)
    //     cout<<q[i].l<<" "<<q[i].r<<endl;
    vector<int> ans(n);
    int cur_l = 0, cur_r = -1 ,cur_ans = 0;
    for(int i=0; i<queries; i++){
        l = q[i].l; r = q[i].r;
        l--; r--;
        // cout<<l<<" "<<r<<endl;
        while(cur_l > l){
            cur_l--;
            cur_ans += arr[cur_l];
        }
        while (cur_r < r){
            cur_r++;
            cur_ans += arr[cur_r];
        }
        while(cur_l < l){
            cur_ans -= arr[cur_l];
            cur_l++;
        }
        while(cur_r > r){
            cur_ans -= arr[cur_r];
            cur_r--;
        }
        ans[i] = cur_ans;
        // cout<<cur_ans<<endl;
    }
    for(int i=0; i<queries; i++)
        cout<<ans[i]<<endl;
    return 0;
}

/*
input
9
1 5 -2 6 8 -7 2 1 11
3
7 8
1 6
2 7
*/