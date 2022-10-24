#include <iostream>
#include <vector>
#include <queue>

// boj 11559 puyo puyo, 구현, 골드 4
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

vector<vector<string>> board(12, vector<string>(6, ""));
vector<vector<string>> removed;

vector<pair<int, int>> bfs(int y, int x, vector<vector<bool>> & visited) {
    vector<pair<int, int>> group;

    string color = board[y][x];
    visited[y][x] = true;

    queue<pair<int, int>> q;
    q.push({y,x});

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        group.push_back(cur);

        for (int i = 0; i < 4; ++i) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if(ny<0 || ny>=12 || nx<0 || nx>=6 || visited[ny][nx]) continue;
            if(board[ny][nx] == color) {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }

    return group;
}

int checkGroup() {
    int group = 0;

    removed = board;
    vector<vector<bool>> visited(12, vector<bool>(6, false));

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 6; ++j) {
            if(board[i][j] != "." && !visited[i][j]) {
                vector<pair<int, int>> puyo = bfs(i,j, visited);
                if(puyo.size()<4) continue;

                group++;

                for (int k = 0; k < puyo.size(); ++k) {
                    removed[puyo[k].first][puyo[k].second] = ".";
                }
            }
        }
    }

    return group;
}

void move() {
    for (int j = 0; j < 6; ++j) {
        vector<string> col;
        for (int i = 11; i >=0; --i) {
            if(removed[i][j] != ".") {
                col.push_back(removed[i][j]);
            }
        }

        int left = col.size();
        if(left == 0) continue;

        for (int i = 0; i < 12-left; ++i) col.push_back(".");

        for (int i = 11; i >=0; --i) {
            removed[i][j] = col[11-i];
        }
    }

    board = removed;
}

int main() {

    for (int i = 0; i < 12; ++i) {
        string row;
        cin>>row;

        for (int j = 0; j < 6; ++j) {
            board[i][j] = row[j];
        }
    }

    int answer = 0;
    while (true) {
        if(checkGroup() == 0) break;
        answer++;
        move();
    }

    cout<<answer;

    return 0;
}
