#include<bits/stdc++.h>
using namespace std;

int main(){
    long n, start, end, s;
    cin>>n;
    vector<long> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    long max_so_far = LONG_MIN, cur_max = 0;
    start = s = end = 0;
    for(int i=0; i<n; i++){
        cur_max += arr[i];
        if(cur_max > max_so_far){
            max_so_far = cur_max;
            start = s;
            end = i;
        }
        if(cur_max<0){
            cur_max = 0;
            s = i+1;
        }
    }
    if(max_so_far > 0)
        cout<<max_so_far<<endl;
    else
        cout<<0<<endl;
    // cout<<start<<" "<<end<<endl;
    arr.erase(arr.begin() + start, arr.begin() + end+1);
    // for(int i=0; i<arr.size(); i++)
    //     cout<<arr[i]<<" ";
    if(arr.size() == 0){
        cout<<0;
        return 0;
    }
    start = s = end = cur_max = 0;
    max_so_far = LONG_MIN;
    for(int i=0; i<arr.size(); i++){
        cur_max += arr[i];
        if(cur_max > max_so_far){
            max_so_far = cur_max;
            start = s;
            end = i;
        }
        if(cur_max<0){
            cur_max = 0;
            s = i+1;
        }
    }
    if(max_so_far > 0)
        cout<<max_so_far<<endl;
    else
    cout<<0<<endl;
    return 0;
}