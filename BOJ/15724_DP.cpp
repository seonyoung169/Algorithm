
#include <iostream>
#include <vector>

// BOJ 15724 주지수, DP
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, T;
    cin>>N>>M;

    vector<vector<int>> dp(N+1, vector<int>(M+1, 0));

    int people;
    // dp 배열 완성 
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin>>people;
            dp[i][j] = people + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    cin>>T;
    int y1, x1, y2, x2;
    
    for (int i = 0; i < T; ++i) {
        cin>>y1>>x1>>y2>>x2;
        // 주어진 영역의 인구 합 구하기 
        int ans = dp[y2][x2] - dp[y1-1][x2] - dp[y2][x1-1] + dp[y1-1][x1-1];
        cout<<ans<<'\n';
    }

    return 0;
}
