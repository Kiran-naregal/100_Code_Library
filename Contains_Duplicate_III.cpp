#include<bits/stdc++.h>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
    int n = nums.size();
    multiset<int> ms;

    int i=0, j=0;
    while(j<n)
    {
        auto up = ms.upper_bound(nums[j]);
        if((up != ms.end() and *up-nums[j] <= t) || (up != ms.begin() and nums[j] - *(--up) <= t))
            return true;
        ms.insert(nums[j]);

        if(ms.size() == k+1)
        {
            ms.erase(nums[i]);
            i++;
        }
        j++;
    }
    return false;
}

int main()
{
    int N,k,t;
    cin >> N >> k >> t;
    vector<int>a;
    for(int i = 0; i < N; i++)
    {
        int d;
        cin >> d;
        a.push_back(d);
    }

    bool x = containsNearbyAlmostDuplicate(a,k,t);
    cout << x << endl;
}