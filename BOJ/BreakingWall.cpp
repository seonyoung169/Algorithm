#include <iostream>
#include <string>
#include <vector>
#include <queue>

// BOJ 2206 벽 부수고 이동하기, BFS 심화 골드 4 
using namespace std;

int MINCOST = 2147483647;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool findMinWay(int N, int M, vector<vector<int>> map) {
    bool found = false;
    vector<vector<vector<int>>> visited(N, vector<vector<int>>(M, vector<int>(2,0)));
    queue<pair<pair<int,int>, int>> q;

    q.push(make_pair(make_pair(0,0), 0));
    visited[0][0][0] = 1;
    visited[0][0][1] = 1;

    while (!q.empty()){
        pair<pair<int, int>, int> loca = q.front();
        q.pop();

        if(loca.first.first == N-1 && loca.first.second == M-1){
            if (!found) found = true;
            if (MINCOST > visited[loca.first.first][loca.first.second][loca.second]){
                MINCOST = visited[loca.first.first][loca.first.second][loca.second];
            }
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int row = loca.first.first + dy[i];
            int col = loca.first.second + dx[i];

            if(row>=0 && row<N && col>=0 && col<M){
                if (map[row][col] == 0){  // 기존에 뚫었던 안뚫었던 그냥 진행하는 경우
                    if(visited[row][col][loca.second] == 0) {  // 처음 방문하면
                        q.push(make_pair(make_pair(row, col), loca.second));
                        visited[row][col][loca.second] = visited[loca.first.first][loca.first.second][loca.second] + 1;
                    }
                }else{
                    if (loca.second == 0){  // 새로 뚫는 경우
                        visited[row][col][1] = visited[loca.first.first][loca.first.second][loca.second] + 1;
                        q.push(make_pair(make_pair(row, col), 1));
                    }
                }
            }
        }
    }

    return found;
}

int main() {
    int N, M;
    cin>>N>>M;

    vector<vector<int>> map(N, vector<int>(M, 0));

    string row;
    for (int i = 0; i < N; ++i) {
        cin>>row;
        for (int j = 0; j < M; ++j) {
            if (row[j] == '1'){
                map[i][j] = 1;
            }
        }
    }

    if (findMinWay(N, M, map)){
        cout<<MINCOST<<'\n';
    }else{
        cout<<-1<<'\n';
    }

    return 0;
}
