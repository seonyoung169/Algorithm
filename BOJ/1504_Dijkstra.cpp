
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

// boj 1504 특정한 최단 경로, 다익스트라, 골드 4 
using namespace std;

int N, E;
int A, B;

vector<vector<pair<int, int>>> edge;

struct cmp {
    bool operator()(pair<int,int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

vector<int> dijkstra(int start) {
    vector<int> cost(N+1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    cost[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        int midNode = pq.top().first;
        int midDist = pq.top().second;
        pq.pop();

        if(midDist > cost[midNode]) continue;


        for (int i = 0; i < edge[midNode].size(); ++i) {
            int nextNode = edge[midNode][i].first;
            int nextDist = edge[midNode][i].second;

            if (cost[nextNode] > midDist + nextDist) {
                cost[nextNode] = midDist + nextDist;
                pq.push({nextNode, cost[nextNode]});
            }
        }
    }

    return cost;
}

int main() {

    cin>>N>>E;

    edge = vector<vector<pair<int, int>>>(N+1, vector<pair<int, int>>());

    for (int i = 0; i < E; ++i) {
        int from, to, dist;
        cin>>from>>to>>dist;
        edge[from].push_back({to, dist});
        edge[to].push_back({from, dist});
    }

    cin>>A>>B;
    if(A>B) {
        int temp = B;
        B = A;
        A = temp;
    }

    int answer;
    vector<int> costStart = dijkstra(1);
    vector<int> costA;
    vector<int> costB;

    if(A==1 && B==N) {
        if (costStart[N]==INT_MAX) answer = -1;
        else answer = costStart[N];
    } else if (A==1) {
        costB = dijkstra(B);
        if (costStart[B]==INT_MAX || costB[N]==INT_MAX) answer = -1;
        else answer = costStart[B] + costB[N];
    } else if (B==N) {
        costA = dijkstra(A);
        if (costStart[A]==INT_MAX || costA[N]==INT_MAX) answer = -1;
        else answer = costStart[A] + costA[N];
    } else {
        costA = dijkstra(A);
        costB = dijkstra(B);
        if (costStart[A]==INT_MAX || costA[B]==INT_MAX || costB[N]==INT_MAX) answer = -1;
        else answer = min(costStart[A] + costA[B] + costB[N], costStart[B] + costB[A] + costA[N]);
    }
    cout<<answer;

    return 0;
}
