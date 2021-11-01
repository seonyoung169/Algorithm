#include <iostream>
#include <vector>

// boj 21610 마법사 상어와 비바라기, 시뮬레이션, 골드 5
using namespace std;

int N, M;

vector<vector<int>> map;
vector<pair<int, int>> moving;

int dy[8] = {0,-1,-1,-1,0,1,1,1};
int dx[8] = {-1,-1,0,1,1,1,0,-1};

int moveCloud(){
    int left = 0;
    int order = 0;
    vector<pair<int, int>> cloud;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i>=N-2 && i<= N-1 && j>=0 && j<=1) {
                cloud.push_back({i, j});
            };
        }
    }

    while (order<M){
        // 구름 이동, 비 1씩 내림, 구름 사라
        int dir = moving[order].first-1, speed = moving[order].second;
        vector<pair<int, int>> new_cloud;
        int row_move = dy[dir] * (speed%N);
        int col_move = dx[dir] * (speed%N);

        vector<vector<bool>> isCloud(N, vector<bool>(N, false));
        for (int i = 0; i < cloud.size(); ++i) {
            int nr = (cloud[i].first + row_move+N) % N;
            int nc = (cloud[i].second + col_move+N) % N;

            map[nr][nc] += 1;
            isCloud[nr][nc] = true;
            new_cloud.push_back({nr, nc});
        }

        for (int i = 0; i < new_cloud.size(); ++i) {
            int count = 0;
            for (int j = 1; j <8 ; j+=2) {
                int nr = new_cloud[i].first + dy[j];
                int nc = new_cloud[i].second + dx[j];

                if (nr<0 || nr>=N || nc<0 || nc>=N) continue;
                if (map[nr][nc]>0) count++;
            }
            map[new_cloud[i].first][new_cloud[i].second] += count;
        }
        new_cloud.clear();
        cloud.clear();

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!isCloud[i][j] && map[i][j]>=2){
                    cloud.push_back({i,j});
                    map[i][j] -= 2;
                }
                if (order==M-1) left += map[i][j];
            }
        }

        order++;
    }

    return left;
}


int main() {
    cin>>N>>M;

    map.assign(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>map[i][j];
        }
    }

    moving.assign(M,{0,0});
    for (int i = 0; i < M; ++i) {
        cin>>moving[i].first>>moving[i].second;
    }

    int answer = moveCloud();
    cout<<answer;

    return 0;
}
