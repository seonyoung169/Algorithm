#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

// 먹을 물고기 후보 정렬 기준 
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    if (a.second != b.second){  // 거리 짧은거
        return a.second < b.second;
    }else {
        if (a.first.first != b.first.first){
            return a.first.first < b.first.first;  // 행 빠른거
        }else{
            return a.first.second < b.first.second;  // 열 빠른거
        }
    }
}

// shark -> fish 까지 dfs 탐색 하면서 도달 가능하면 true
bool isCatchable(vector<vector<int>> sea, pair<int, int> shark, pair<int, int> fish, int sharkSize, int & cost){
    bool able = false;

    vector<vector<bool>> visited(sea.size(), vector<bool>(sea.size()));

    queue<pair<pair<int, int>, int>> points;
    points.push(make_pair(shark, 0));
    visited[shark.first][shark.second] = true;

    while (!points.empty()){
        pair<pair<int, int>, int> loc = points.front();
        points.pop();

        if (loc.first == fish){
            if (!able) able = true;

            if (cost > loc.second) {
                cost = loc.second;
            }

            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int r = loc.first.first + dy[i];
            int c = loc.first.second + dx[i];

            if (r>=0 && r<sea.size() && c>=0 && c<sea.size()){
                if (sea[r][c] <= sharkSize && !visited[r][c]){
                    visited[r][c] = true;
                    points.push(make_pair(make_pair(r, c), loc.second + 1));
                }
            }
        }
    }


    return able;
}

int getBabySharkTime(vector<vector<int>> sea, vector<pair<int, int>> fishes, pair<int, int> shark){
    int N = sea.size();
    int second = 0;
    int sharkSize = 2;
    int yum = 0;

    while (!fishes.empty()){
        // 가서 먹을 수 있는 물고기 골라내기
        vector<pair<pair<int, int>, int>> eatable;

        for (int i = 0; i < fishes.size(); ++i) {
            int dist = 2147483647;
            // 도달 가능한지 확인 - BFS
            if (isCatchable(sea, shark, fishes[i], sharkSize, dist)){
                eatable.push_back(make_pair(fishes[i], dist));
            }
        }

        // 엄마 상어 호출
        if (eatable.size() == 0) break;

        // eatable 물고기들을 기준에 맞게 정렬 -> eatable[0] 가 먹을놈
        if (eatable.size() > 1) {
            sort(eatable.begin(), eatable.end(), comp);
        }

        // 물고기 먹으러
        sea[shark.first][shark.second] = 0;
        shark = eatable[0].first;
        second += eatable[0].second;
        sea[shark.first][shark.second] = 9;

        // 먹고 사이즈 갱신 확인 
        yum++;
        if (yum == sharkSize){
            yum = 0;
            sharkSize++;
        }

        // 새롭게 먹을 수 있는 물고기 확인 
        fishes.clear();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (sea[i][j] >= 1 && sea[i][j] <= 6 && sea[i][j] < sharkSize){
                    fishes.push_back(make_pair(i, j));
                }
            }
        }
    }


    return second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin>>N;

    vector<vector<int>> sea(N, vector<int>(N, 0));
    vector<pair<int, int>> fishes;
    pair<int, int> shark;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>sea[i][j];

            if (sea[i][j] == 9) {
                shark = make_pair(i, j);
            }else if (sea[i][j] >= 1 && sea[i][j]<=6 && sea[i][j] < 2){
                fishes.push_back(make_pair(i,j));
            }
        }
    }

    int second = getBabySharkTime(sea, fishes, shark);

    cout<<second;


    return 0;
}
