#include <iostream>
#include <vector>

// BOJ 1520 내리막길, DFS + DP 로 풀기
using namespace std;

vector<vector<int>> map;
vector<vector<int>> dp;

int dy[4] = {-1, 0, 1,0};
int dx[4] = {0, 1, 0, -1};

int DFS(int row, int col, int M, int N){
    // 도착지점 
    if (row == M-1  && col == N-1) return 1;
    
    // 한번 방문되어 dp 값이 저장되엉 있는 경우라면 다시 방문하지 말고 해당 dp 값 가져와서 더라기 
    if (dp[row][col] != -1) return dp[row][col];

    // 경로수를 더하기 위해 해당 값을 -1 -> 0으로 
    dp[row][col] = 0;
    for (int i = 0; i < 4; ++i) {
        int nr = row + dy[i];
        int nx = col + dx[i];

        // 지도 범위 내 현재 위치보다 낮은 곳으로 재귀 진행 
        if (nr>=0 && nr<M && nx>=0 && nx<N && map[nr][nx] < map[row][col]) {
            dp[row][col] += DFS(nr, nx, M, N);
        }
    }

    return dp[row][col];
}
int main() {
    int M, N;
    cin>>M>>N;

    dp.assign(M, vector<int>(N, -1));
    map.assign(M, vector<int>(N, 0));
    for (int i = 0; i < M; ++i) {
        for (int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }

    // 0,0 에서 M-1, N-1까지 갈 수 있는 경로수  =  DFS(0,0, M, N)
    int answer = DFS(0,0, M, N);

    cout<<answer;

    return 0;
}
