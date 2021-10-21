#include <iostream>
#include <vector>
#include <queue>

// boj 17386 공주님을 구해라!, BFS, 골드 5
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int MINTIME = -1;
vector<vector<int>> castle;

bool savePrincess(int N, int M, int T){
    bool result = false;
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(M+1, vector<int>(2, 10001)));

    queue<pair<pair<int, int>, int>> point;
    point.push({{1,1}, 0});
    dp[1][1][0] = 0;

    while (!point.empty()){
        int row = point.front().first.first;
        int col = point.front().first.second;
        int flag = point.front().second;
        point.pop();

        if (row==N && col==M){
            result = true;
            continue;
        }

        if (dp[row][col][flag] == T) continue;

        for (int i = 0; i < 4; ++i) {
            int nr = row + dy[i];
            int nc = col + dx[i];

            if (nr<1 || nr>N || nc<1 || nc>M ) continue;
            if (castle[nr][nc] == 1 && flag == 0) continue; // 벽인데 검이 없으면 pass
            if (dp[nr][nc][flag] != 10001 &&  dp[row][col][flag]+1 >= dp[nr][nc][flag]) continue;


            if(castle[nr][nc] == 2){
                dp[nr][nc][1] = dp[row][col][flag] + 1;
                point.push({{nr, nc}, 1});
            }else{
                dp[nr][nc][flag] = dp[row][col][flag] + 1;
                point.push({{nr, nc}, flag});
            }
        }
    }

    if(result){
        MINTIME = min(dp[N][M][0], dp[N][M][1]);
    }

    return result;
}


int main() {
    int N, M, T;
    cin>>N>>M>>T;

    castle.assign(N+1,vector<int>(M+1));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin>>castle[i][j];
        }
    }

    if (savePrincess(N, M, T)){
        cout<<MINTIME;
    }else{
        cout<<"Fail";
    }

    return 0;
}
