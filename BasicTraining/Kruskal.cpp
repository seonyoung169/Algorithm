#include <iostream>
#include <vector>
#include <algorithm>

//Kruskal Algorithm
using namespace std;

// 하나의 간선 정보
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

//부모 노드 번호를 반환하는 함수
int getParent(vector<int> & parents, int x){
    if(parents[x] == x) return x; // 최종 부모 노드이면 반환
    else return getParent(parents, parents[x]);
}
//두 노드를 연결시키는 함수
void unionParent(vector<int> & parents, int a, int b){
    a = getParent(parents, a);
    b = getParent(parents, b);
    if(a < b) parents[b] = a;
    else parents[a] = b;
}

//두 노드 a, b가 같은 그래프 안에 있는지 확인하는 함수
bool findParent(vector<int> & parents, int a, int b){
    a = getParent(parents, a);
    b = getParent(parents, b);
    if(a == b) return 1;
    else return 0;
}

int main(){
    int node = 7;

    vector<Edge> v;
    v.push_back(Edge(1,7,12));
    v.push_back(Edge(1,4,28));
    v.push_back(Edge(1,2,67));
    v.push_back(Edge(1,5,17));
    v.push_back(Edge(2,4,24));
    v.push_back(Edge(2,5,62));
    v.push_back(Edge(3,5,20));
    v.push_back(Edge(3,6,37));
    v.push_back(Edge(4,7,13));
    v.push_back(Edge(5,6,45));
    v.push_back(Edge(5,7,73));

    sort(v.begin(), v.end());

    vector<int> parent(node+1);
    for(int i=0; i<node+1; i++){
        parent[i] = i;
    }

    int sum=0;
    for(int i=0; i<v.size(); i++){
        if(!findParent(parent, v[i].node1, v[i].node2)){
            sum += v[i].distance;
            unionParent(parent, v[i].node1, v[i].node2);
        }

    }

    cout<<sum<<'\n';

    return 0;
}
