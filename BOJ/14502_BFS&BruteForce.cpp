#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// BOJ 14502 연구소, Brute Force + BFS, 골드 5
using namespace std;

int N, M;
vector<vector<int>> map;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

// 내림 차순
bool desc(int a, int b){
    return a>b;
}

// 벽을 세우는 가능한 모든 경우의 수 구하기
vector<vector<pair<int, int>>> getCombinations(vector<pair<int, int>> blanks) {
    vector<vector<pair<int, int>>> combinations;
    vector<bool> select;

    for (int i = 0; i < blanks.size()-3; ++i) {
        select.push_back(false);
    }
    select.push_back(true);
    select.push_back(true);
    select.push_back(true);

    do{
        vector<pair<int, int>> combi;
        for (int i = 0; i < blanks.size(); ++i) {
            if (select[i]) {
                combi.push_back(blanks[i]);
            }
        }
        combinations.push_back(combi);
    }while (next_permutation(select.begin(), select.end()));

    return combinations;
}

// 바이러스 퍼지기
int doBFS(vector<vector<int>> & testMap, pair<int ,int> start, vector<vector<bool>> & visited){
    queue<pair<int ,int>> points;
    points.push(start);
    visited[start.first][start.second] = true;

    while (!points.empty()){
        pair<int, int> loc = points.front();
        points.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = loc.first + dy[i];
            int nc = loc.second + dx[i];

            if (nr>=0 && nr<N && nc>=0 && nc<M && !visited[nr][nc]) {
                if (testMap[nr][nc] != 1){
                    visited[nr][nc] = true;
                    points.push(make_pair(nr, nc));

                    if (testMap[nr][nc] == 0){
                        testMap[nr][nc] = 2;
                    }
                }
            }
        }
    }

    int safe = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (testMap[i][j] == 0) safe++;
        }
    }

    return safe;
}

int getMaxSafeArea(vector<pair<int, int>> blanks){
    vector<vector<pair<int, int>>> combinations = getCombinations(blanks);
    vector<int> safeAreas;

    for (int i = 0; i < combinations.size(); ++i) {
        vector<vector<int>> testMap = map;
        testMap[combinations[i][0].first][combinations[i][0].second] = 1;
        testMap[combinations[i][1].first][combinations[i][1].second] = 1;
        testMap[combinations[i][2].first][combinations[i][2].second] = 1;

        vector<vector<bool>> visited(N, vector<bool>(M, false));

        int area;
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                if (testMap[j][k] == 2 && !visited[j][k]){
                    area = doBFS(testMap, make_pair(j, k), visited);
                }
            }
        }
        safeAreas.push_back(area);
    }

    sort(safeAreas.begin(), safeAreas.end(), desc);

    return safeAreas[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    map.assign(N, vector<int>(M, 0));

    vector<pair<int, int>> blanks;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin>>map[i][j];
            if (map[i][j]==0) {
                blanks.push_back(make_pair(i,j));
            }
        }
    }

    int answer = getMaxSafeArea(blanks);

    cout<<answer;

    return 0;
}
