#include <iostream>
#include <vector>
#include <algorithm>

// DFS 기본 문제 (BOJ 1260 문제 기준)
using namespace std;

void DFS(vector<vector<int>> & graph, vector<int> & checked, int nextNode){
    if(checked.at(nextNode)) return;
    else{
        checked[nextNode] = 1;
        cout<<nextNode<<" ";
        for(int i=0; i<graph[nextNode].size(); i++){
            int node = graph[nextNode][i];
            DFS(graph, checked, node);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, V, a, b;
    cin>>N>>M>>V;
    vector<vector<int>> graph(N+1);

    for(int i=0; i<M; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<=N; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    vector<int> checked(N+1);
    for(int i=0; i<N+1; i++){
        checked[i] = 0;
    }

    DFS(graph,checked, V);
    cout<<"\n";

    return 0;
}
