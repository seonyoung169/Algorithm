#include <iostream>
#include <vector>
#include <queue>

// BOJ 1600 말이 되고픈 원숭이, 골드 4, 유사문제 boj 벽 부수고 이동하기
using namespace std;

int dy[12] = {-2, -1, 1, 2, 2, 1, -1, -2, -1, 0, 1, 0};
int dx[12] = {1, 2, 2, 1, -1, -2,-2, -1, 0, 1, 0, -1};

int getMinStep(vector<vector<int>> map, int K){
    bool able = false;  // 도달 가능한지 

    int MIN = 2147483647;
    int H = map.size();
    int W = map[0].size();

    pair<int, int> destination = make_pair(H-1, W-1);
    
    // 현재까지의 이동 수 기록 & 방문 여부 체크용 3차원 배열, 말을 k번 사용해서 이동한 비용은  visited[y][x][k]에 저장된다. 
    vector<vector<vector<int>>> visited(H, vector<vector<int>>(W, vector<int>(K+1, 0)));

    queue<pair<pair<int, int>,  int>> points;
    points.push(make_pair(make_pair(0,0), 0));
    visited[0][0][0] = 0;

    while (!points.empty()){
        // 현재 지점 
        pair<pair<int, int>, int> loc = points.front();
        points.pop();

        // 목적지인지 확인, 최소 비용 갱신
        if (loc.first == destination){
            if (MIN > visited[loc.first.first][loc.first.second][loc.second]){
                MIN = visited[loc.first.first][loc.first.second][loc.second];
            }
            if (!able) able = true;
            continue;
        }

        // 0-7 : 말 이동 8가지  +  8-11 : 일반이동 4가지 확인 
        for (int i = 0; i < 12; ++i) {
            int r = loc.first.first + dy[i];
            int c = loc.first.second + dx[i];

            // 지도 범위 내, 빈칸인지 확인 
            if (r>=0 && r<H && c>=0 && c<W && map[r][c] == 0){
                if (i < 8){  
                    // 말 이동 가능 & 방문 할 수 있는 곳이면 
                    if (loc.second < K && visited[r][c][loc.second+1] == 0){
                        // 말 사용횟수 추가 (loc.second + 1)
                        visited[r][c][loc.second+1] = visited[loc.first.first][loc.first.second][loc.second] + 1;
                        points.push(make_pair(make_pair(r,c), loc.second+1));
                    }
                }else{
                    // 방문할 수 있는 곳이면 
                    if (visited[r][c][loc.second] == 0){
                        // 말 사용 횟수 유지 (loc.second)
                        visited[r][c][loc.second] = visited[loc.first.first][loc.first.second][loc.second] + 1;
                        points.push(make_pair(make_pair(r,c), loc.second));
                    }
                }
            }

        }
    }

    if (able) return MIN;
    else return -1;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int K, W, H;
    cin>>K>>W>>H;

    vector<vector<int>> map(H, vector<int>(W,0));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin>>map[i][j];
        }
    }

    int step = getMinStep(map, K);
    cout<<step;

    return 0;
}
