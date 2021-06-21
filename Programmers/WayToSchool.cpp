#include <vector>
#include <queue>

// 프로그래머스 DP 등굣길 level 3
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> town(n+1, vector<int>(m+1,0));
    vector<vector<bool>> visited (n+1, vector<bool>(m+1, false));
    queue<pair<int, int>> points;

    town[1][1] = 1;
    points.push(make_pair(1,1));

    for (int i = 0; i < puddles.size() ; ++i) {
        int r = puddles[i][1];
        int c = puddles[i][0];
        town[r][c] = -2;
    }

    while (!points.empty()){
        int row = points.front().first;
        int col = points.front().second;

        if (visited[row][col]){
            points.pop();
            continue;
        }

        if (row-1 >= 1 && town[row-1][col] != -2){
            town[row][col] += town[row-1][col];
        }

        if (col-1 >= 1 && town[row][col-1] != -2){
            town[row][col] += town[row][col-1];
        }

        town[row][col] = town[row][col] % 1000000007;

        visited[row][col] = true;
        points.pop();

        if (row+1 <= n && col <= m && !visited[row+1][col] && town[row+1][col] != -2){
            points.push(make_pair(row+1, col));
        }
        if (row <= n && col +1 <= m && !visited[row][col+1] && town[row][col+1] != -2){
            points.push(make_pair(row, col+1));
        }

    }

    return town[n][m] ;
}
