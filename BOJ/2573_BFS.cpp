#include <iostream>
#include <vector>
#include <queue>

// BOJ 2573 빙산, BFS 골드 4, 시간초과 해결 개오래걸림,,,ㅋㅋ 
using namespace std;

int N, M;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void BFS(int y, int x, vector<vector<int>> map, vector<vector<bool>> & visited, vector<pair<pair<int, int>, int>> & pointAndSea){
    queue<pair<int, int>> points;

    points.push(make_pair(y, x));
    visited[y][x] = true;

    while (!points.empty()){
        pair<int, int> location = points.front();
        points.pop();

        int sea = 0;
        if (map[location.first + dy[0]][location.second + dx[0]] == 0) sea++;
        if (map[location.first + dy[1]][location.second + dx[1]] == 0) sea++;
        if (map[location.first + dy[2]][location.second + dx[2]] == 0) sea++;
        if (map[location.first + dy[3]][location.second + dx[3]] == 0) sea++;

        pointAndSea.push_back(make_pair(location, sea));

        for (int i = 0; i < 4; ++i) {
            int row = location.first + dy[i];
            int col = location.second + dx[i];

            if (map[row][col] > 0 && !visited[row][col]){
                visited[row][col] = true;
                points.push(make_pair(row, col));
            }
        }
    }
}

int getMinYears(vector<vector<int>> map, vector<pair<int, int>> icePoints){
    int years = 0;

    while (icePoints.size() > 0){
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        // 덩어리 갯수 확인
        int continent = 0;
        vector<pair<pair<int, int>, int>> pointAndSea;
        for (int i = 0; i < icePoints.size(); ++i) {
            if (!visited[icePoints[i].first][icePoints[i].second]){
                continent++;
                BFS(icePoints[i].first, icePoints[i].second, map, visited, pointAndSea);
            }
        }

        // 덩어리가 2개 이상이면 종료
        if (continent >= 2) break;

        // 빙산 녹이기
        years++;
        icePoints.clear();
        for (int i = 0; i < pointAndSea.size(); ++i) {

            if (map[pointAndSea[i].first.first][pointAndSea[i].first.second] < pointAndSea[i].second){
                map[pointAndSea[i].first.first][pointAndSea[i].first.second] = 0;
            }
            else map[pointAndSea[i].first.first][pointAndSea[i].first.second] -= pointAndSea[i].second;

            if (map[pointAndSea[i].first.first][pointAndSea[i].first.second] > 0){
                icePoints.push_back(make_pair(pointAndSea[i].first.first, pointAndSea[i].first.second));
            }
        }

        if (icePoints.size() == 0 ){
            years = 0;
            break;
        }

    }

    return years;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    vector<vector<int>> map(N, vector<int>(M));
    vector<pair<int, int>> icePoints;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin>>map[i][j];
            if (map[i][j] > 0){
                icePoints.push_back(make_pair(i,j));
            }
        }
    }

    int answer = getMinYears(map, icePoints);
    cout<<answer;

    return 0;
}
