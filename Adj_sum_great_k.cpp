#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, sum;
    cin>>n>>sum;
    if(sum > (n+1)){
        cout<<-1<<endl;
        return;
    }
    bool even_ele = false, sum_even = false;
    int i,j=1;
    if(n%2 == 0){
        even_ele = true;
    }
    if(sum%2 == 0){
        sum_even = true;
    }
    for(i=1; i<=n; i++){
        if(j<=sum/2 && even_ele && !sum_even){
            cout<<(j)<<" "<<(sum-j)<<" ";
            i++;
            j++;
        }
        else if(j<=sum/2 && !even_ele && sum_even){
            if(j == sum/2){
                cout<<j<<" ";
                if(sum<n)
                    cout<<sum;
                j++;
                i++;
                continue;
            }
            cout<<(j)<<" "<<(sum-j)<<" ";
            i++;
            j++;
        }
        else if(j<=sum/2 && !even_ele && !sum_even){
            cout<<(j)<<" "<<(sum-j)<<" ";
            i++;
            j++;
        }
        else if(j <= (sum/2) && even_ele && sum_even){
            if(j == sum/2){
                cout<<j<<" "<<sum<<" ";
                j=j+2;
                i++;
                continue;
            }
            cout<<j<<" "<<sum-j<<" ";
            j++;
            i++;
        }
        else
            cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    
    return 0;
}