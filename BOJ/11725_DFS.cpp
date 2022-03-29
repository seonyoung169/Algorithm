#include <iostream>
#include <vector>

// boj 11725 트리의 부모 찾기, 실버 2, dfs
using namespace std;

vector<int> adjacent[100001];
bool visited[100001];
int parent[100001];

void dfs(int cur) {
    visited[cur] = true;

    for (int i = 0; i < adjacent[cur].size(); ++i) {
        int adj = adjacent[cur][i];
        if (visited[adj]) continue;
        parent[adj] = cur;
        dfs(adj);
    }
}

int main() {
    int N;
    cin>>N;

    for (int i = 0; i <N-1; ++i) {
        int a, b;
        cin>>a>>b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <=N ; ++i) {
        cout<<parent[i]<<'\n';
    }

    return 0;
}
