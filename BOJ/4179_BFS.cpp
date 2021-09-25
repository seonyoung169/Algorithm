#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

// boj 4179 불!, bfs 이용, 시뮬레이션, 골드 4
using namespace std;

int MINTIME;
int R, C;

vector<vector<char>> map;
vector<vector<int>> fire_sec;
vector<vector<int>> jihoon_sec;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void fire_bfs(queue<pair<int, int>> fire){

    while (!fire.empty()){
        pair<int, int> curr = fire.front();
        fire.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = curr.first + dy[i];
            int nc = curr.second + dx[i];

            if (nr>=0 && nr<R && nc>=0 && nc<C && map[nr][nc] != '#' && fire_sec[nr][nc] == -1){
                fire_sec[nr][nc] = fire_sec[curr.first][curr.second] + 1;
                fire.push(make_pair(nr, nc));
            }
        }
    }
}

bool escapable(pair<int, int> start){
    bool possible = false;

    queue<pair<int, int>> points;
    points.push(start);

    while (!points.empty()){
        pair<int, int> curr = points.front();
        points.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = curr.first + dy[i];
            int nc = curr.second + dx[i];

            if (nr<0 || nr>=R || nc<0 || nc>=C){
                if(!possible) possible = true;

                if (MINTIME > jihoon_sec[curr.first][curr.second] + 1){
                    MINTIME = jihoon_sec[curr.first][curr.second] +1;
                }
                continue;
            }

            if (jihoon_sec[nr][nc] != -1 || map[nr][nc] == '#') continue;
            if (fire_sec[nr][nc] == -1 || (fire_sec[nr][nc] != -1 && fire_sec[nr][nc] > jihoon_sec[curr.first][curr.second] + 1)){
                jihoon_sec[nr][nc] = jihoon_sec[curr.first][curr.second] + 1;
                points.push(make_pair(nr, nc));
            }
        }
    }

    return possible;
}

int main() {
    cin>>R>>C;

    MINTIME = INT_MAX;
    map.assign(R, vector<char>(C));
    fire_sec.assign(R, vector<int>(C,-1));
    jihoon_sec.assign(R, vector<int>(C, -1));

    pair<int, int> start;
    queue<pair<int,int>> fire;

    for (int i = 0; i < R; ++i) {
        string row;
        cin>>row;
        for(int j = 0; j < C; j++){
            map[i][j] = row[j];
            if (map[i][j] == 'J'){
                start = make_pair(i, j);
                jihoon_sec[i][j] = 0;
            } else if (map[i][j] == 'F'){
                fire.push(make_pair(i, j));
                fire_sec[i][j] = 0;
            }
        }
    }

    if (start.first == 0 ||start.first == R-1 || start.second == 0|| start.second == C-1){
        MINTIME = 1;
        cout<<MINTIME;
    }else{
        fire_bfs(fire);

        if (escapable(start)){
            cout<<MINTIME;
        }else{
            cout<<"IMPOSSIBLE";
        }
    }

    return 0;
}
