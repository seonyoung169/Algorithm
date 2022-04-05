#include <iostream>
#include <vector>

// boj 16918 봄버맨, 그래프탐색인데 시뮬로 풀었음, 실버 1
using namespace std;

vector<vector<char>> matrix;
vector<vector<int>> installTime;

int dy[5] = {0,-1,0,1,0};
int dx[5] = {0,0,1,0,-1};

void installBomb(int R, int C, int sec){
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j){
            if (matrix[i][j]=='.') {
                matrix[i][j] = 'O';
                installTime[i][j] = sec;
            }
        }
    }
}

void removeBomb(int R, int C, vector<pair<int, int>> points){
    for (int i = 0; i < points.size(); ++i) {
        for (int k = 0; k < 5; ++k) {
            int row = points[i].first+dy[k], col = points[i].second+dx[k];
            if (row<0||row>=R||col<0||col>=C) continue;
            matrix[row][col] = '.';
            installTime[row][col] = -1;
        }
    }
}

void moveMan(int R, int C, int N){
    int sec = 1;

    while (sec<N){
        sec++;
        installBomb(R, C, sec);

        if (sec==N) break;

        sec++;
        vector<pair<int, int>> remove_points;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j){
                if (sec-installTime[i][j]==3){
                    remove_points.push_back({i,j});
                }
            }
        }

        removeBomb(R, C, remove_points);
    }
}

int main() {
    int R, C, N;
    cin>>R>>C>>N;

    matrix.assign(R, vector<char>(C, ' '));
    installTime.assign(R, vector<int>(C, -1));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin>>matrix[i][j];
            if (matrix[i][j] =='O') installTime[i][j] = 0;
        }
    }

    moveMan(R, C, N);

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j){
            cout<<matrix[i][j];
        }
        cout<<'\n';
    }


    return 0;

}
