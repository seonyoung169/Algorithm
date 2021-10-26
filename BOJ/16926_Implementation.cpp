#include <iostream>
#include <vector>

// boj 16926 배열 돌리기, 복잡 구현, 실버 2
using namespace std;

vector<vector<int>> map;

// 이동 방향 0 : 아래로, 1 : 오른쪽으로, 2 : 위로, 3 : 왼쪽으로
// 이동 방향별 다음 index 값 변화 
int dy[4] = {+1,0,-1,0};  
int dx[4] = {0,1,0,-1};

void rotateMap(int N, int M, int R){
    int count = R;
    int cycle = min(N, M)/2;

    while (count>0){  // R 번 진행 
        count--;
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        for (int i = 0; i < cycle; ++i) {  // 배열 내에 생기는 사이클 만큼 교환 진행 
            int dir = 0;
            pair<int, int> cur = {i, i};
            pair<int, int> next = {cur.first+dy[dir], cur.second+dx[dir]};

            int before = map[cur.first][cur.second];
            int after = map[next.first][next.second];

            while (!visited[next.first][next.second]){
                map[next.first][next.second] = before;// 값 교체 후 
                visited[next.first][next.second] = true;

                before = after;

                cur = next;  //다음 위치로 이동 
                next = {cur.first+dy[dir], cur.second+dx[dir]};
                
                // 다음 위치가 범위 벗어나면 이동 방향 변화 
                if (next.first<i || next.first>=N-i || next.second<i || next.second>=M-i){
                    if(dir<3){
                        dir++;
                        next = {cur.first+dy[dir], cur.second+dx[dir]};
                    }else{
                        break;
                    }
                }

                after = map[next.first][next.second];

            }

        }
    }
}

int main() {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, R;
    cin>>N>>M>>R;

    map.assign(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin>>map[i][j];
        }
    }

    rotateMap(N,M,R);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
