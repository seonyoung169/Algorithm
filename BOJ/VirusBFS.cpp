#include <iostream>
#include <vector>
#include <queue>

//BOJ 2606 BFS로 풀기, 맞음!
using namespace std;

int result = 0;
queue<int> q;

void virusSearch(vector<vector<int>> & graph){
    vector<int> visited(graph.size(), 0);

    while (!q.empty()){
        int now = q.front();
        q.pop();

        if(!visited[now]){
            visited[now] = 1;
            if(now != 1) result++;

            for(int i=0; i<graph[now].size(); i++){
                int neighbor = graph[now][i];
                if(!visited[neighbor]){
                    q.push(neighbor);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, a, b;
    cin>>N>>M;

    vector<vector<int>> graph(N+1);
    for(int i=0; i<M; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    q.push(1);

    virusSearch(graph);

    cout<<result<<'\n';

    return 0;
}
