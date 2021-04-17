#include <iostream>
#include <vector>
#include <string>
#include <stack>

// BOJ 1987 알파벳, DFS 이용
using namespace std;

vector<vector<char>> board;
vector<bool> alphabetAppear;
vector<vector<bool>> visited;

int r[4] = {1,-1,0,0};
int c[4] = {0,0,1,-1};

int answer = 0;

void DFS(int R, int C, int row, int col, int area){
    for (int i = 0; i < 4 ; ++i) {
        int nextRow = row + r[i];
        int nextCol = col + c[i];

        if(nextRow >=0 && nextRow < R && nextCol >= 0 && nextCol <C){
            char nextCh = board[nextRow][nextCol];

            if(!alphabetAppear[nextCh-65] && !visited[nextRow][nextCol]){
                alphabetAppear[nextCh-65] = true;
                visited[nextRow][nextCol] = true;

                DFS(R, C, nextRow, nextCol, area+1);

                alphabetAppear[nextCh-65] = false;
                visited[nextRow][nextCol] = false;
            }
        }
    }
    answer = max(answer, area);

}

int main() {
    int R, C;
    cin>>R>>C;

    int area = 1;
    board.assign(R, vector<char>(C, ' '));
    visited.assign(R, vector<bool>(C, false));
    alphabetAppear.assign(26, false);


    string str;
    for (int i = 0; i <R ; ++i) {
        cin>>str;
        for (int j = 0; j < C; ++j) {
            board[i][j] = str[j];
        }
    }

    char start = board[0][0];
    alphabetAppear[start-65] = true;

    DFS(R, C, 0, 0, area);

    cout<<answer<<'\n';

    return 0;
}
