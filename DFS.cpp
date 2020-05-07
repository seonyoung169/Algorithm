#include <iostream>
#include <vector>

//그래프 이용 -> DFS 알고리즘 (방향성 없는 그래프)

using namespace std;

class Graph {
private:
    int N;
    vector<vector<int>> adj;
    int *visited;

public:
    Graph(int n) {
        this->N = n;
        for (int i = 0; i < N; ++i) {
            vector<int> element(0);
            adj.push_back(element);
        }
    }

    void addEdge(int v, int w) {
        adj[v-1].push_back(w-1);
        adj[w-1].push_back(v-1);
    }

    void DFSUtil(int v) {
        visited[v] = 1;
        cout << v+1 << " ";

        for (int i = 0; i < adj[v].size(); i++) {
            if (adj[v][i] != NULL) {
                int next = adj[v][i];
                if (!visited[next]) {
                    DFSUtil(next);
                }
            }
        }
    }

    void DFS() {
        visited = new int[N];
        for (int i = 0; i < N; i++) visited[i] = 0;

        for (int j = 0; j < N; ++j) {
            if (!visited[j]) {
                DFSUtil(j);
            }
        }
    }
};

int main() {
    int N;
    cin >> N;

    Graph g(N);
    g.addEdge(1, 5);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.DFS();

    return 0;
}
