//
// Created by SEONYOUNG LEE on 2020/05/13.
//
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

//백준 1260 - DFS

void DFS(int ** adj, int N, int V){
    bool * visited = new bool[N];
    bool flag;
    for(int i=0;i<N;i++){
        visited[i] = false;
    }

    stack<int> st;
    int next;

    st.push(V);
    visited[V-1] = true;
    cout<<V<<" ";
    cout.flush();

    while(!st.empty()){
        next = st.top();
        st.pop();
        flag = false;

        for(int i=0;i<N;i++){
            if(adj[next-1][i] == 1 && !visited[i]){
                st.push(i+1);
                flag = true;
                visited[i] = true;
                cout << (i+1) <<" ";
                cout.flush();
                break;
            }
        }

        //더이상 방문할 노드가 없으면 stack 모두 pop
        if(!flag) st.pop();
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


    DFS(adj, N, V);
    
    return 0;
}
