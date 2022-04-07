#include <string>
#include <vector>
#include <set>

// 프로그래머스 프렌즈4블록, 시뮬? 구현?
using namespace std;

vector<vector<char>> matrix;

int countRemovable(int m, int n){
    set<pair<int, int>> check;
    vector<vector<char>> removed = matrix;

    for (int i = 1; i <= m-1; ++i) {
        for (int j = 1; j <= n-1; ++j) {
            if ( matrix[i][j]!='-' && matrix[i][j] == matrix[i][j+1]  && matrix[i][j] == matrix[i+1][j] && matrix[i][j] == matrix[i+1][j+1]) {
                removed[i][j] = '-';
                if (check.find({i, j}) == check.end()) check.insert({i, j});
                removed[i][j + 1] = '-';
                if (check.find({i, j + 1}) == check.end()) check.insert({i, j + 1});
                removed[i + 1][j] = '-';
                if (check.find({i + 1, j}) == check.end()) check.insert({i + 1, j});
                removed[i + 1][j + 1] = '-';
                if (check.find({i + 1, j + 1}) == check.end()) check.insert({i + 1, j + 1});
            }
        }
    }
    matrix = removed;

    return check.size();
}

void arrangeBlock(int m, int n){

    for (int j = 1; j <= n; ++j) {
        vector<char> col;
        for (int i = m; i >= 1; --i) {
            if (matrix[i][j] != '-') col.push_back(matrix[i][j]);
        }

        for (int i = 0; i < col.size(); ++i) {
            matrix[m-i][j] = col[i];
        }

        if (col.size() == m) continue;
        for (int i = m-col.size(); i >= 1; --i) matrix[i][j] = '-';
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    matrix.assign(m+1, vector<char>(n+1, ' '));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) matrix[i][j] = board[i-1][j-1];
    }

    int removable = countRemovable(m,n);
    answer += removable;
    while (removable > 0){
        arrangeBlock(m,n);
        removable = countRemovable(m,n);
        answer += removable;
    }

    return answer;
}

int main() {
    int sol;
    sol = solution(6,6, {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"});

    cou
    return 0;
}
