#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    void DFS_end(int);
    void DFS();
    void add_ele(int, int);
};

void graph::DFS_end(int a){
    cout<<a<<" ";
    visited[a] = true;
    list<int>::iterator i;
    for(i = adj[a].begin(); i != adj[a].end(); i++)
        if(!visited[*i])
            DFS_end(*i);
}

void graph::DFS(){
    for(auto x:adj){
        if(visited[x.first]==false){
            DFS_end(x.first);
        }
    }
}

void graph::add_ele(int a, int b){
    adj[a].push_back(b);
}

int main(){
    int n_edge, a, b;
    graph g1;
    cin>>n_edge;
    for(int i=0; i<n_edge; i++){
        cin>>a>>b;
        g1.add_ele(a,b);
    }
    g1.DFS();
    return 0;
}

/*
input
7
0 1
0 2
1 2
2 0
2 3
3 3
4 4
*/