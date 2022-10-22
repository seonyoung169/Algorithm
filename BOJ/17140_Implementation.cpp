#include <iostream>
#include <vector>
#include <algorithm>

// boj 17140 이차원 배열과 연산, 구현, 골드 4
using namespace std;

int R, C, K;
int N = 3, M = 3;

vector<vector<int>> board(101, vector<int>(101,0));

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return a.first<b.first;
    }
    return a.second <= b.second;
}

void operationR() {

    vector<vector<int>> newBoard;
    int maxCol = 0;

    for (int i = 0; i < N; ++i) {
        vector<int> count(101, 0);
        for (int j = 0; j < M; ++j) {
            if(board[i][j]==0) continue;
            count[board[i][j]] += 1;
        }

        vector<pair<int, int>> exist;
        for (int j = 1; j <= 100; ++j) {
            if (count[j] == 0) continue;
            exist.push_back({j,count[j]});
        }
        sort(exist.begin(), exist.end(), cmp);

        for (int j = 0; j < exist.size(); ++j) {
            board[i][2*j] = exist[j].first;
            board[i][2*j+1] = exist[j].second;
        }

        int pushed = exist.size() * 2;
        if(pushed>100) pushed = 100;

        for (int j = pushed; j < 101; ++j) {
            board[i][j] = 0;
        }

        if(maxCol<100) maxCol = max(maxCol, pushed);
    }

    M = maxCol;
}

void operationC() {
    vector<vector<int>> newBoard(101, vector<int>(101, 0));
    int maxRow = 0;

    for (int j = 0; j < M; ++j) {
        vector<int> count(101, 0);
        for (int i = 0; i < N; ++i) {
            if (board[i][j] == 0) continue;
            count[board[i][j]] += 1;
        }

        vector<pair<int, int>> exist;
        for (int i = 1; i <= 100; ++i) {
            if (count[i] == 0) continue;
            exist.push_back({i,count[i]});
        }
        sort(exist.begin(), exist.end(), cmp);

        for (int i = 0; i < exist.size(); ++i) {
            board[2*i][j] = exist[i].first;
            board[2*i+1][j] = exist[i].second;
        }

        int pushed = exist.size() * 2;
        if(pushed>100) pushed = 100;

        if(pushed<100) {
            for (int i = pushed; i < 100; ++i) {
                board[i][j] = 0;
            }
        }

        if (maxRow < 100) maxRow = max(maxRow, pushed);
    }

    N = maxRow;
}

int solve() {
    int sec = 0;

    if (R<=N && C<=M && board[R-1][C-1]==K) return sec;

    while (sec<100) {
        sec++;
        if(N>=M) {
            operationR();
        } else {
            operationC();
        }

        if (R<=N && C<=M && board[R-1][C-1]==K) {
            return sec;
        }
    }

    return -1;
}

int main() {

    cin>>R>>C>>K;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin>>board[i][j];
        }
    }

    cout<<solve();

    return 0;
}
