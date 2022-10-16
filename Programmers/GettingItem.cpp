#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <limits.h>

// 프로그래머스 아이템줍기, bfs, level 3
using namespace std;

vector<vector<int>> board(102, vector<int>(102, 0));

int answer = INT_MAX;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int zero_dy[4] = {0,-1,-1,0};
int zero_dx[4] = {0,0,-1,-1};

struct Point {
    int y;
    int x;
    int dist;
    Point(int r, int c, int d) : y(r), x(c), dist(d) {};
};

bool onEdge(int row, int col) {
    int cnt = 0;

    for (int i = 0; i < 4; ++i) {
        int ny = row + zero_dy[i];
        int nx = col + zero_dx[i];

        if(board[ny][nx] == 0) cnt++;
    }

    if(cnt == 0 || cnt == 4) return false;
    return true;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {

    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    for (int i = 0; i < rectangle.size(); ++i) {
        for (int j = rectangle[i][0]*2; j < rectangle[i][2]*2 ; ++j) {
            for (int k = rectangle[i][1]*2; k < rectangle[i][3]*2 ; ++k) {
                board[j][k] += 1;
            }
        }
    }

    queue<Point> q;
    q.push(Point(characterX, characterY, 0));

    vector<vector<bool>> visited(102, vector<bool>(102, false));
    visited[characterX][characterY] = true;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        if(cur.y == itemX && cur.x == itemY) {
            answer = min(answer, cur.dist);
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if(ny<1 || ny>100 || nx<1 || nx>100) continue;
            if(visited[ny][nx]) continue;
            if(!onEdge(ny, nx)) continue;

            visited[ny][nx] = true;

            q.push(Point(ny, nx, cur.dist+1));
        }
    }

    return answer/2;
}

int main() {

    int ans = solution({{1,1,7,4},{3,2,5,5},{4,3,6,9},{2,6,8,8}}, 1,3,7,8);

    cout<<ans;

    return 0;
}
