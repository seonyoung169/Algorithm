#include <iostream>
#include <vector>
#include <queue>

// boj 5547 일루미네이션 실버1, bfs
using namespace std;

int even_dy[6] = {-1,0,1,1,0,-1};
int even_dx[6] = {0,1,0,-1,-1,-1};

int odd_dy[6] = {-1,0,1,1,0,-1};
int odd_dx[6] = {1,1,1,0,-1,0};

int R, C;

int bfs(vector<vector<int>> map, vector<vector<bool>> & visited,int row, int col){
    int edge = 0;

    queue<pair<int, int>> point;
    point.push({row, col});
    visited[row][col] = true;

    while (!point.empty()){
        pair<int,int> cur = point.front();
        point.pop();

        for (int i = 0; i < 6; ++i) {
            int move_row, move_col;

            if (cur.first % 2 == 0){
                move_row = even_dy[i];
                move_col = even_dx[i];
            }else{
                move_row = odd_dy[i];
                move_col = odd_dx[i];
            }

            int nr = cur.first + move_row;
            int nc = cur.second + move_col;

            if (nr<0 || nr>R+1 || nc<0 || nc>C+1) continue;

            if (map[nr][nc]== 2) edge++;
            else{
                if (!visited[nr][nc]){
                    visited[nr][nc] = true;
                    point.push({nr,nc});
                }
            }

        }
    }

    return edge;
}

void makeOutsideWall(vector<vector<int>> & map, int R, int C){
    vector<vector<bool>> visited(R+2, vector<bool>(C+2, false));
    queue<pair<int,int>> point;

    point.push({0,0});
    visited[0][0] = true;

    while (!point.empty()){
        pair<int, int> loc = point.front();
        map[loc.first][loc.second] = 2;
        point.pop();

        int move_r, move_c;
        for (int k = 0; k < 6; ++k) {
            if (loc.first%2==0) {
                move_r = even_dy[k];
                move_c = even_dx[k];
            }else{
                move_r = odd_dy[k];
                move_c = odd_dx[k];
            }

            int nr = loc.first+move_r;
            int nc = loc.second+move_c;

            if(nr<0||nr>R+1||nc<0||nc>C+1) continue;
            if (map[nr][nc]==0 && !visited[nr][nc]){
                visited[nr][nc] = true;
                point.push({nr,nc});
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>C>>R;

    vector<vector<int>> map(R+2, vector<int>(C+2,0));
    vector<vector<bool>> visited(R+2, vector<bool>(C+2, false));

    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) cin>>map[i][j];
    }

    makeOutsideWall(map, R, C);


    int answer = 0;
    for (int i = 0; i <= R+1 ; ++i) {
        for (int j = 0; j <= C+1 ; ++j) {
            if (!visited[i][j] && map[i][j]== 1){
                answer += bfs(map, visited, i, j);
            }
        }
    }

    cout<<answer;

   return 0;
}
