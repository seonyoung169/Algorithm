#include <iostream>
#include <vector>
#include <map>

// boj 1913 달팽이, 실버 3, 구현 
using namespace std;

int N, Q;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

map<int, pair<int,int>> location;
vector<vector<int>> board;

void write() {
    int center = (N+1)/2;
    board[center][center] = 1;
    location.insert({1, make_pair(center,center)});

    int curNum = 2, layer = 2, dir = 0;
    pair<int, int> pos = {center-1, center};

    while (curNum<=N*N){
        board[pos.first][pos.second] = curNum;
        location.insert({curNum, pos});

        curNum++;

        if (curNum>N*N) break;

        int range_from = (2*layer-3) * (2*layer-3) +1;
        int range_to = (2*layer-1) * (2*layer-1);

        if (curNum >= range_from && curNum <= range_to) {
            int ny = pos.first + dy[dir];
            int nx = pos.second + dx[dir];

            if (ny<(center-layer+1) || ny>(center+layer-1) || nx<(center-layer+1) || nx>(center+layer-1)) {
                dir = (dir+1) % 4;
                pos = make_pair(pos.first + dy[dir], pos.second + dx[dir]);
            } else {
                pos = make_pair(ny, nx);
            }
        } else {
            layer++;
            pos = make_pair(pos.first-1, pos.second);
            dir = 0;
        }
    }
}

int main() {
    cin>>N>>Q;

    board.resize(N+1, vector<int>(N+1, 0));

    write();

    for (int i = 1; i <=N ; ++i) {
        for (int j = 1; j <=N; ++j) {
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<location[Q].first<<' '<<location[Q].second<<'\n';

    return 0;
}
