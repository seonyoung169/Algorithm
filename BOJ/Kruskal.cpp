#include <iostream>
#include <vector>
#include <algorithm>

// BOJ 1197 최소 신장 트리 - 크루스컬 사용, 맞음
using namespace std;

class Edge {
public:
    int node1;
    int node2;
    int distance;

    Edge(int a, int b, int distance){
        this->node1 = a;
        this->node2 = b;
        this->distance = distance;
    }
    bool operator <(const Edge & edge) const {
        return (this->distance < edge.distance);
    }
};

int getParent(vector<int> & parents, int x){
    if(parents[x] == x) return x;
    else return getParent(parents, parents[x]);
}

void unionParent(vector<int> & parents, int a, int b){
    int p1 = getParent(parents, a);
    int p2 = getParent(parents, b);
    if(p1<p2) {
        for(int i=0; i<parents.size(); i++){
            if(parents[i] == p2) parents[i] = p1;
        }
    }
    else {
        for(int i=0; i<parents.size(); i++){
            if(parents[i] == p1) parents[i] = p2;
        }
    }
}

bool findParent(vector<int> & parents, int a, int b){
    int p1 = getParent(parents, a);
    int p2 = getParent(parents, b);
    if(p1 == p2) return true;
    else return false;
}

int kruskal(vector<Edge> & edges, int N){
    int distanceSum = 0;
    vector<int> parents(N+1);

    for(int i=0; i<N+1; i++){
        parents[i] = i;
    }

    for(int i=0; i<edges.size(); i++){
        if(!findParent(parents, edges[i].node1, edges[i].node2)){
            distanceSum += edges[i].distance;
            unionParent(parents, edges[i].node1, edges[i].node2);
        }
    }

    return distanceSum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int V, E, A, B, C;
    vector<Edge> edges;
    cin>>V>>E;

    for(int i=0; i<E; i++){
        cin>>A>>B>>C;
        edges.push_back(Edge(A,B,C));
    }

    sort(edges.begin(), edges.end());

    cout<<kruskal(edges, V)<<'\n';

    return 0;
}
