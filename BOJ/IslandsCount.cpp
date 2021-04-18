#include <iostream>
#include <vector>
#include <queue>

// BOJ 4963 섬의 갯수, BFS & DFS
using namespace std;

int r[8] = {-1,-1,0,1,1,1,0,-1};
int c[8] = {0,1,1,1,0,-1,-1,-1};

void DFS(int row, int col, int R, int C,  vector<vector<int>> ground, vector<vector<bool>> & visited){
    if (row < 0 || row >= R || col < 0 || col >= C) return;
    if (visited[row][col]) return;
    if (ground[row][col] == 0) return;

    visited[row][col] = true;

    for (int i = 0; i <8 ; ++i) {
        int newRow = row+r[i];
        int newCol = col+c[i];
        DFS(newRow, newCol, R, C, ground, visited);
    }
}

void BFS(vector<vector<int>> ground, queue<pair<int, int>> q, int R, int C, vector<vector<bool>> & visited){
    while (!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

//        visited[row][col] = true;

        for (int i = 0; i < 8 ; ++i) {
            int nextRow = row + r[i];
            int nextCol = col + c[i];

            if(nextRow>=0 && nextRow<R && nextCol>=0 && nextCol< C){
                if(!visited[nextRow][nextCol] && ground[nextRow][nextCol]){
                    visited[nextRow][nextCol] = true;
                    q.push(make_pair(nextRow, nextCol));
                }
            }
        }

    }
}


int main() {
    int C, R;
    cin>>C>>R;

    vector<int> answer;

    while (!(C==0 && R==0)) {
        vector<vector<int>> ground(R, vector<int>(C, 0));
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        queue<pair<int, int>> q;

        int island = 0;
        for(int i=0; i<R; i++) {
            for (int j = 0; j < C; ++j) {
                cin>>ground[i][j];
            }
        }

        for(int i=0; i<R; i++) {
            for (int j = 0; j < C; ++j) {
                if (ground[i][j] == 1 && !visited[i][j]){
                    island++;
                    q.push(make_pair(i,j));
                    visited[i][j] = true;
                    BFS(ground, q, R, C, visited);
//                    DFS(i, j, R, C, ground, visited);
                }
            }
        }

        answer.push_back(island);

        cin>>C>>R;
    }


    for (int i = 0; i < answer.size() ; ++i) {
        cout<<answer[i]<<'\n';
    }

}
