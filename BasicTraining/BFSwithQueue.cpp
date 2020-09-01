//
// Created by SEONYOUNG LEE on 2020/05/13.
//
#include <iostream>
#include <stack>
#include <queue>

//백준 1260번 - BFS

using namespace std;

void BFS(int ** adj, int N, int V) {
    bool * visited = new bool[N];
    for(int i=0; i<N; i++){
        visited[i] = false;
    }
    bool flag;
    int next;

    queue<int> q;
    q.push(V);
    visited[V-1] = true;

    while(!q.empty()){
        next = q.front();
        q.pop();
        cout<<next<<" ";
        cout.flush();

        for(int i=0;i<N;i++){
            if(adj[next-1][i] == 1 && !visited[i]){
                q.push(i+1);
                visited[i] = true;
            }
        }
    }
}

int main(){
    int N, M, V;
    int row, col;

    cin>>N>>M>>V;

    //간선 배열 0으로 초기화
    int ** adj = new int*[N];
    for(int i=0;i<N;i++){
        adj[i] = new int[N];
        memset(adj[i], 0, sizeof(int)*N);
    }

    for(int i=0; i<M; i++){
        cin>>row>>col;
        adj[row-1][col-1] = 1;
        adj[col-1][row-1] = 1;
    }

    BFS(adj, N, V);

    return 0;
}
