#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, x;
    cin>>n>>m>>x;
    int races[n];
    for(int i=0; i<n ; i++)
        cin>>races[i];
    sort(races, races+n);
    int i, wins[m], index = 0, temp=0;
    for( i=0;i<m;i++){
        temp=0;
        while(races[index]==(i+1)){
            temp++;
            index++;
        }
        wins[i] = temp;
    }
    sort(wins, wins+m);
    if(n - index < x){x = n - index;}
    for(int k=0; k<m; k++)
        cout<<wins[k]<<" ";
    cout<<endl;
    for(int j=index; j<(index + x); j++){
        wins[0]++;
        i=0;
        temp = wins[0];
        while (temp > wins[i+1] && i<(m-1)){
            wins[i] = wins[i+1];
            i++;
        }
        wins[i] = temp;
        for(int k=0; k<m; k++)
            cout<<wins[k]<<" ";
        cout<<endl;
    }
    cout<<wins[0]<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}

/*
3
7 2 2
1 3 2 2 2 2 1
5 3 1
1 1 3 5 5
4 2 2
1 2 2 3


1
4 3 0
4 5 6 5
1
8 3 4
1 3 3 3 4 5 6 7 
*/