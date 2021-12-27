#include <iostream>
#include <vector>

// boj 2615 오목, 구현, 실버 3
using namespace std;

int dy[8] = {-1,0,1,1,1,0,-1,-1};
int dx[8] = {1,1,1,0,-1,-1,-1,0};

int result = 0;
int start_row = -1, start_col = -1;

vector<vector<int>> map(20,vector<int>(20,0));

bool search(int row, int col, int dir){
    int r_dir = (dir+4) % 8;
    int r_row = row + dy[r_dir], r_col = col + dx[r_dir];

    // 시작점 기준 역방향 체크
    if (!(r_row<0||r_row>=19||r_col<0||r_col>=19) && map[r_row][r_col]==map[row][col]) return false;

    int count = 1;
    for (int i = 1; i <= 5; ++i) {
        int nr = row + dy[dir]*i, nc = col + dx[dir]*i;

        if (nr<0||nr>=19||nc<0||nc>=19) break;
        if (map[nr][nc]==map[row][col]) count++;
        else break;
    }

    if (count==5) return true;
    return false;
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            cin>>map[i][j];
        }
    }

    for (int i =0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            if ((map[i][j]==1 || map[i][j]==2)){
                for (int k = 0; k < 4; ++k) {
                    if (search(i, j, k)){
                        result = map[i][j];
                        start_row = i+1, start_col = j+1;
                    }
                }
            }
            if (result != 0) break;
        }
        if (result != 0) break;
    }

    cout<<result<<'\n';
    if (result!=0){
        cout<<start_row<<' '<<start_col<<'\n';
    }

   return 0;
}
