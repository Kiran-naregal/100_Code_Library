#include<bits/stdc++.h>
using namespace std;

class item{
    public:
        int wt, val;
        item(int wt,int val){
            this->wt = wt;
            this->val = val;
        }
};

static bool cmp(item a, item b){
    double r1 = (double)a.val/(double)a.wt;
    double r2 = (double)b.val/(double)b.wt;
    return r1>r2;
}

double fractional_knapsack(vector<item> ele, int max_wt){
    sort(ele.begin(), ele.end(), cmp);
    for(int i=0; i<ele.size(); i++){
        cout<<ele[i].val<<" "<<ele[i].wt<<endl;
    }
    double cur_wt = 0, ans = 0;
    for(int i=0; i<ele.size(); i++){
        if(max_wt-cur_wt >= ele[i].wt){
            cur_wt += ele[i].wt;
            ans += ele[i].val;
        }
        else{
            ans += ele[i].val / ele[i].wt * (max_wt - cur_wt);
            break;
        }
    }
    return ans;
    
}

int main(){
    int n, a, b;
    cin>>n;
    vector<item> arr;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        item temp(a,b);
        arr.push_back(temp);
    }
    int max;
    cin>>max;
    cout<<fractional_knapsack(arr, max);
    return 0;
}
/*
3
10 60
20 100
30 120
50
*/