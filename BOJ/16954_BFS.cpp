#include <iostream>
#include <vector>
#include <string>
#include <queue>

// boj 16954 움직이는 미로 탈출, 골드 4, bfs
using namespace std;

int dy[9] = {0,-1,-1,0,1,1,1,0,-1};
int dx[9] = {0,0,1,1,1,0,-1,-1,-1};

vector<vector<char>> map(8, vector<char>(8));

bool isArrivable(){
    queue<pair<int,int>> points;
    points.push({7,0});

    while (!points.empty()){

        vector<vector<bool>> visited(8, vector<bool>(8, false));
        int size = points.size();
        for (int i = 0; i < size; ++i) {
            pair<int, int> cur = points.front();
            points.pop();

            if (map[cur.first][cur.second] == '#') continue;
            if (cur.first == 0){
                return true;
            }

            for (int j = 0; j < 9; ++j) {
                int ny = cur.first + dy[j];
                int nx = cur.second + dx[j];

                if (ny<0 || ny>=8 || nx<0 || nx>=8) continue;
                if (map[ny][nx] == '#' || visited[ny][nx]) continue;

                points.push({ny,nx});
                visited[ny][nx] = true;
            }
        }

        for (int i = 7; i >=0 ; i--) {
            for (int j = 0; j < 8; ++j) {
                if (i==0) map[i][j] == '.';
                else{
                    map[i][j] = map[i-1][j];
                }
            }
        }
    }

    return false;
}


int main() {

    for (int i = 0; i < 8; ++i) {
        string row;
        cin>>row;
        for (int j = 0; j < 8; ++j) {
            map[i][j] = row[j];
        }
    }

    cout<<isArrivable();

    return 0;
}
