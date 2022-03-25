#include <iostream>
#include <vector>
#include <queue>

// 프로그래머스 level 2, 게임 맵 최단 거리, bfs 
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1, 0,1,0};

struct point {
    int r;
    int c;
    int dis;

    point(int row, int col, int distance){
        r = row;
        c = col;
        dis = distance;
    }
};

int solution(vector<vector<int>> maps){
    int answer = -1;
    int n = maps.size(), m = maps[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<point> q;
    q.push(point(0,0,1));

    while (!q.empty()){
        point cur = q.front();
        q.pop();

        if (cur.r == n-1 && cur.c == m-1){
            if(answer==-1) answer = cur.dis;
            else {
                if (answer>cur.dis) answer = cur.dis;
            }
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = cur.r + dy[i];
            int nc = cur.c + dx[i];

            if (nr<0||nr>=n||nc<0||nc>=m) continue;
            if (maps[nr][nc] == 0) continue;

            if (!visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push(point(nr, nc, cur.dis+1));
            }
        }
    }

    return answer;
}
