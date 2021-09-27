#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

// boj 1753 최단경로, 골드 5, 다익스트라 사용
using namespace std;

vector<vector<pair<int, int>>> edges;

struct cmp {
    bool operator()(pair<int, int> & a, pair<int, int> & b){
        return a.first > b.first;
    }
};


void dijkstra(int V, int start){
    vector<int> path(V+1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    path[start] = 0;
    pq.push(make_pair(0, start));


    while (!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (cost > path[node]) continue;

        for (int i = 0; i < edges[node].size(); ++i) {
            int dest = edges[node][i].first;
            int destCost = edges[node][i].second;

            if (path[dest] > cost + destCost){
                path[dest] = cost + destCost;
                pq.push(make_pair(path[dest], dest));
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        if (path[i] == INT_MAX) cout<<"INF";
        else cout<<path[i];
        cout<<"\n";
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, K;
    cin>>V>>E>>K;

    edges.assign(V+1, vector<pair<int,int>>());

    for (int i = 0; i < E; ++i) {
        int from, to, weight;
        cin>>from>>to>>weight;

        edges[from].push_back(make_pair(to, weight));
    }

    dijkstra(V,K);

    return 0;
}
