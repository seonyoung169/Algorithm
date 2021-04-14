#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 프로그래머스 그래프 가장 먼 노드, level 2
using namespace std;

bool desc(int a, int b){
    return a>b;
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 1;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    vector<int> distances(n+1,0);
    vector<bool> visited(n+1, false);
    queue<int> q;

    for (int i=0; i<edge.size(); i++){
        int r = edge[i][0];
        int c = edge[i][1];
        graph[r][c] = 1;
        graph[c][r] = 1;
    }

    q.push(1);
    while (!q.empty()){
        int location = q.front();
        q.pop();

        visited[location] = true;

        for (int i=2; i<=n; i++){
            if (!visited[i] && distances[i]==0 && graph[location][i] == 1){
                distances[i] = distances[location]+1;
                q.push(i);

            }
        }
    }

    sort(distances.begin(), distances.end(), desc);
    for (int i = 1; i <=n ; ++i) {
        if(distances[i] != distances[i-1]) break;
        answer++;
    }
    return answer;
}

int main() {
    int ans;
    ans = solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});

    cout<<ans<<'\n';

    return  0;
}
