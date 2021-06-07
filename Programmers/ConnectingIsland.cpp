#include <vector>
#include <algorithm>

// 프로그래머스 greedy - 섬 연결하기, level 3
using namespace std;

bool byCost(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

void unionParent(vector<int> & parent, int a, int b){
    int before, after;
    if (parent[a]<parent[b]) {
        before = parent[b];
        after = parent[a];
    } else {
        before = parent[a];
        after = parent[b];
    }
    for (int i = 0; i < parent.size(); ++i) {
        if (parent[i] == before) parent[i] = after;
    }
}

bool isSameParent(vector<int> & parent, int a, int b){
    if (parent[a]== parent[b]) return true;
    else return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int island = 0, start;
    vector<int> parent(n);

    for(int i=0; i<n; i++){
        parent[i] = i;
    }

    sort(costs.begin(), costs.end(), byCost);

    unionParent(parent, costs[0][0], costs[0][1]);
    start = costs[0][0];
    island += 2;
    answer += costs[0][2];
    costs.erase(costs.begin());

    while (island<n){
        int i=0;
        bool connected = false;

        while (!connected) {
            if (isSameParent(parent, start, costs[i][0]) && isSameParent(parent, start, costs[i][1])){
                costs.erase(costs.begin()+i);
            }else if (isSameParent(parent, start, costs[i][0]) || isSameParent(parent, start, costs[i][1])){
                connected = true;
            }else i++;
        }

        unionParent(parent, start, costs[i][0]);
        unionParent(parent, start, costs[i][1]);
        answer += costs[i][2];
        costs.erase(costs.begin()+i);
        island += 1;
    }

    return answer;
}
