#include <iostream>
#include <vector>
#include <map>

using namespace std;
//boj 2578 빙고, 구현, 실버 5

vector<vector<int>> board(25,vector<int>(25,0));

int checkRow(){
    int row = 0;

    for (int i = 0; i < 5; ++i) {
        int count = 0;
        for (int j = 0; j < 5; ++j) {
            if (board[i][j]==-1) count++;
        }
        if (count==5) row++;
    }

    return row;
}

int checkCol() {
    int col = 0;

    for (int i = 0; i < 5; ++i) {
        int count = 0;
        for (int j = 0; j < 5; ++j) {
            if (board[j][i]==-1) count++;
        }
        if (count==5) col++;
    }

    return col;
}

int checkCross() {
    int cross = 0;

    int right = 0, left = 0;
    for (int i = 0; i < 5; ++i) {
        if (board[i][i]==-1) right++;
        if (board[i][4-i]==-1) left++;
    }

    if (right==5) cross++;
    if (left==5) cross++;

    return cross;
}

int main() {
    int answer = 0;

    map<int, pair<int, int>> location;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin>>board[i][j];
            location[board[i][j]] = {i,j};
        }
    }

    int erase;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin>>erase;
            board[location[erase].first][location[erase].second] = -1;
            if (checkRow()+checkCol()+checkCross() >= 3) {
                answer = 5*i + j + 1;
                break;
            }
        }
        if(answer!=0) break;
    }

    cout<<answer<<'\n';
    
    return 0;
}
