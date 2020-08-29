#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// BFS 기본 문제 (BOJ 1260 문제 기준)
using namespace std;

void BFS(vector<vector<int>> & graph, int N, int start){
    int visited[N+1];
    queue<int> q;

    for(int i=0; i<N+1; i++){
        visited[i] = 0;
    }

    q.push(start);
    visited[start] = 1;

    while (!q.empty()){
        int nextNode = q.front();
        q.pop();
        cout<<nextNode<<" ";

        for(int i=0; i<graph[nextNode].size(); i++){
            int node = graph[nextNode][i];

            if(!visited[node]){
                q.push(node);
                visited[node] = 1;
            }
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

    BFS(graph, N, V);

    return 0;
}
