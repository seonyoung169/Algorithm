#include <iostream>
#include <vector>
#include <stdlib.h>
#include <queue>

// BOJ 16234 인구이동, 시뮬레이션
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

// 지도상에 존재하는 연합 - 연합에 포함되는 국가들 좌표와 인구 합 
typedef struct unite{
    int totalPopulation;
    vector<pair<int, int>> countries;

    unite() {
        totalPopulation = 0;
        countries = vector<pair<int, int>>();
    }
}Unite;

// 지도상에 위치하는 연합 구하기 
Unite bfs(vector<vector<int>> map, vector<vector<bool>> & visited, int i, int j, int N, int L, int R){
    Unite unite;
    queue<pair<int, int>> q;

    q.push(make_pair(i, j));
    visited[i][j] = true;

    while (!q.empty()){
        pair<int, int> location = q.front();
        q.pop();

        unite.totalPopulation += map[location.first][location.second]; 
        unite.countries.push_back(location);

        for (int k = 0; k < 4; ++k) {
            int r = location.first + dy[k];
            int c = location.second + dx[k];

            if (r>=0 && r<N && c>=0 && c<N){ // 지도 범위 내
                int diff = abs(map[location.first][location.second] - map[r][c]); // 인구 차이

                if (diff >= L && diff <= R && !visited[r][c]){ // 조건에 맞으면 연합으로, 모든 좌표 한번씩만 방문 
                    q.push(make_pair(r, c));
                    visited[r][c] = true;
                }
            }
        }
    }

    return unite;
}

int getMovigDays(vector<vector<int>> map, int N, int L, int R) {
    int moved = 0;

    while (true) {
        vector<Unite> unites;
        vector<vector<bool>> visited(N, vector<bool>(N, false));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {

                for (int k = 0; k < 4; ++k) {
                    int r = i + dy[k];
                    int c = j + dx[k];

                    if (r >= 0 && r < N && c >= 0 && c < N && !visited[r][c]) { // 지도 범위 내
                        int diff = abs(map[i][j] - map[r][c]);

                        if (diff >= L && diff <= R) { //시작 지점 발견하면 BFS 시작
                            Unite unite = bfs(map, visited, i, j, N, L, R);
                            unites.push_back(unite);  // 연합들을 알아낸 뒤 
                        }
                    }
                }
            }
        }

        if (unites.size() > 0) {  // 연합이 존재 하면 인구 이동 시작 
            moved++;
            for (int i = 0; i < unites.size(); ++i) {
                int avg = unites[i].totalPopulation / unites[i].countries.size();
                for (int j = 0; j < unites[i].countries.size(); ++j) {
                    pair<int, int> c = unites[i].countries[j];
                    map[c.first][c.second] = avg;
                }
            }

        } else {
            break;
        }
    }

    return moved;
}


int main() {
    int N, L, R;
    cin>>N>>L>>R;

    vector<vector<int>> map(N, vector<int>(N,0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>map[i][j];
        }
    }

    int answer = getMovigDays(map, N, L, R);

    cout<<answer;

    return 0;
}
