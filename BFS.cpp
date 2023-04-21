#include<bits/stdc++.h>
using namespace std;

class graph{
    vector<list<int>> edge;
    int v=0;
    public:
        graph(int a){
            v=a;
            edge.resize(v);
        }
        void BFS();
        void add_edge(int, int);
};

void graph::add_edge(int a, int b){
    edge[a].push_back(b);
}

void graph::BFS(){
    vector<int> visited(v, false);
    queue<int> temp;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            visited[i] = true;
            temp.push(i);
            while (temp.size() != 0){
                cout<<temp.front()<<" ";
                for(auto x:edge[temp.front()]){
                    if(!visited[x]){
                        visited[x]=true;
                        temp.push(x);
                    }
                }
                temp.pop();
            }
        }
    }
}

int main(){
    int v, n_edge, a, b;
    cin>>v>>n_edge;
    graph bfs(v);
    for(int i=0; i<n_edge; i++){
        cin>>a>>b;
        bfs.add_edge(a, b);
    }
    bfs.BFS();
    return 0;
}

/*
4 6
0 1
0 2
1 2
2 0
2 3
3 3

o/p
0 1 2 3
*/