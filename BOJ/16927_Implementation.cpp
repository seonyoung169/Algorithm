#include <iostream>
#include <vector>

// boj 16927 배열 돌리기2, 골드 5, 구현 
using namespace std;

int N, M, R;

vector<vector<int>> board;

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

void rotate(int cycle, int len) {
    int r = R % len;

    while (r>0) {
        int dir = 0;
        pair<int, int> start = {cycle, cycle};
        pair<int, int> cur = start;

        int row_max = N-cycle+1, col_max = M-cycle+1;
        int before = board[cycle][cycle], after = -1;

        while (dir<4) {
            pair<int, int> next = {cur.first + dy[dir],cur.second + dx[dir]};

            if (next.first<cycle || next.first>row_max || next.first<cycle || next.second>col_max) {
                dir++;
                next = {cur.first + dy[dir],cur.second + dx[dir]};
            }

            if (next == start) {
                board[next.first][next.second] = before;
                break;
            }

            after = board[next.first][next.second];
            board[next.first][next.second] = before;
            before = after;
            cur = next;

        }
        r--;
    }
}

int main() {
    cin>>N>>M>>R;

    board.resize(N+1, vector<int>(M+1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M ; ++j) {
            cin>>board[i][j];
        }
    }

    int totalCycle = min(N, M)/2;
    for (int i = 0; i < totalCycle; ++i){
        int n = N-(2*i), m = M-(2*i);
        int len = n*m - (n-2)*(m-2);
        rotate(i+1, len);
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M ; ++j) {
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
