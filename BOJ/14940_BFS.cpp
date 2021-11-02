#include <iostream>
#include <vector>
#include <queue>

// boj 14940 쉬운 최단거리, bfs, 골드 5
using namespace std;

vector<vector<int>> map;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void getDistance(int N, int M, pair<int, int> destination){
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    visited[destination.first][destination.second] = true;

    vector<vector<int>> distance(N, vector<int>(M, 0));
    distance[destination.first][destination.second] = 0;

    queue<pair<int, int>> points;
    points.push(destination);


    while (!points.empty()){
        int cur_row = points.front().first;
        int cur_col = points.front().second;
        points.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = cur_row + dy[i];
            int nc = cur_col + dx[i];

            if (nr<0||nr>=N||nc<0||nc>=M) continue;
            if (visited[nr][nc]) continue;

            visited[nr][nc] = true;

            if (map[nr][nc] == 1) {
                distance[nr][nc] = distance[cur_row][cur_col] + 1;
                points.push({nr, nc});
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j]==1 && distance[i][j]==0) cout<<-1<<' ';
            else cout<<distance[i][j]<<' ';
        }
        cout<<'\n';
    }

}

int main() {
    int N, M;
    cin>>N>>M;

    pair<int, int> dest;

    map.assign(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin>>map[i][j];
            if (map[i][j]==2) dest = {i,j};
        }
    }

    getDistance(N, M, dest);

    return 0;
}
