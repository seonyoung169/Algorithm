#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

// boj 1939 중량제한, 이분탐색 + bfs, 골드4
using namespace std;

int N, M, from, to;
vector<vector<pair<int, int>>> adjacent;

bool isAvailable(int mid) {
    vector<bool> visited(N+1, false);
    visited[from] = true;

    queue<int> island;
    island.push(from);

    while (!island.empty()){
        int cur = island.front();
        island.pop();

        if (cur == to) return true;

        for (auto iter : adjacent[cur]){
            int next = iter.first, weight = iter.second;
            if(!visited[next] && weight >= mid){
                visited[next] = true;
                island.push(next);
            }
        }
    }

    return false;
}

int solution(int from, int to, int left, int right){
    int answer = -1;

    while (left<=right){
        int mid = (left+right)/2;

        if (isAvailable(mid)){
            answer = mid;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }

    return answer;
}

int main() {
    int left = INT_MAX, right = -1;
    cin>>N>>M;

    adjacent.resize(N+1);
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin>>a>>b>>c;
        adjacent[a].push_back({b, c});
        adjacent[b].push_back({a, c});
        if (c<left) left = c;
        if (c>right) right = c;
    }
    cin>>from>>to;

    int answer = solution(from, to, left, right);
    cout<<answer;

    return 0;
}
