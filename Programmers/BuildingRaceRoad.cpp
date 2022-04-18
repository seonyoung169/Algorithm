#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

// 프로그래머스 경주로 건설, level 3, bfs + dp
using namespace std;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

struct point {
    int row, col, dir;
    point(int y, int x, int d, int c) {
        row = y;
        col = x;
        dir = d;
    }
};

int solution(vector<vector<int>> board) {
    int N = board.size();
    int visited[26][26][4];
    fill(&visited[0][0][0], &visited[25][25][3], INT_MAX);
    for (int i = 0; i < 4; ++i) visited[0][0][i] = 0;

    queue<point> loc;
    loc.push(point(0,0,0, 0));

    while (!loc.empty()) {
        point cur = loc.front();
        loc.pop();

        if (cur.row == N-1 && cur.col == N-1) continue;

        for (int d = 0; d < 4; ++d) {
            int nr = cur.row + dy[d], nc = cur.col + dx[d];

            if (nr<0||nr>=N||nc<0||nc>=N) continue;
            if (board[nr][nc]==1) continue;

            int ncost = 0;
            if (cur.row==0 && cur.col==0){
                ncost = 100;
            }else{
                ncost = visited[cur.row][cur.col][cur.dir] + 100;
                if (cur.dir != d) ncost += 500;
            }

            if (visited[nr][nc][d] > ncost) {
                visited[nr][nc][d] = ncost;
                loc.push(point(nr, nc, d, ncost));
            }
        }
    }

    int answer = visited[N-1][N-1][0];
    for (int i = 1; i <4 ; ++i) {
        if(answer > visited[N-1][N-1][i]) answer = visited[N-1][N-1][i];
    }

    return answer;
}
