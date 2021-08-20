#include <iostream>
#include <vector>
#include <algorithm>

// BOJ 16562 친구비, 유니온파인드 사용, 골드 3
using namespace std;

vector<int> cost;
vector<int> parent;

//부모 노드 번호를 반환하는 함수
int getParent(int x){
    if(parent[x] == x) return x; // 최종 부모 노드이면 반환
    else return getParent(parent[x]);
}
//두 노드를 연결시키는 함수
void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(cost[a] <= cost[b]) parent[b] = a;
    else parent[a] = b;
}
int getMinCost(vector<pair<int, int>> relation){
    int total = 0;
    vector<int> finalParents;

    for (int i = 0; i < relation.size(); ++i) {
        unionParent(relation[i].first, relation[i].second);
    }

    for (int i = 1; i < parent.size(); ++i) {
        finalParents.push_back(getParent(i));
    }

    sort(finalParents.begin(), finalParents.end());
    finalParents.erase(unique(finalParents.begin(), finalParents.end()), finalParents.end());

    for (int i = 0; i < finalParents.size(); ++i) {
        total += cost[finalParents[i]];
    }

    return total;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, k;
    cin>>N>>M>>k;

    cost.assign(N+1, 0);
    parent.assign(N+1, 0);
    vector<pair<int, int>> relation(M, make_pair(0,0));

    for (int i = 1; i < N+1; ++i) {
        cin>>cost[i];
        parent[i] = i;
    }

    int totalCost = 0;
    if (M==0){
        for (int i = 1; i <= N ; ++i) {
            totalCost += cost[i];
        }
    }else{
        for (int i = 0; i < M; ++i) {
            cin>>relation[i].first>>relation[i].second;
        }
        totalCost = getMinCost(relation);
    }

    if (totalCost > k){
        cout<<"Oh no";
    }else{
        cout<<totalCost;
    }

    return 0;
}
