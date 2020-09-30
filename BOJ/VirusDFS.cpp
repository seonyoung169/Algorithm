#include <iostream>
#include <vector>
#include <stack>

//BOJ 2606 DFS로 풀기 
using namespace std;

int result = 0;
stack<int> st;

void virusSearch(vector<vector<int>> & graph){
    vector<int> visited(graph.size(), 0);

    while (!st.empty()){
        int now = st.top();
        st.pop();

        if(!visited[now]){
            visited[now] = 1;
            if(now != 1) result++;

            for(int i=0; i<graph[now].size(); i++){
                int neighbor = graph[now][i];
                if(!visited[neighbor]){
                    st.push(neighbor);
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
    }
    st.push(1);

    virusSearch(graph);

    cout<<result<<'\n';

    return 0;
}
