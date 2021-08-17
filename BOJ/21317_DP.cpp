#include <iostream>
#include <vector>

// BOJ 21317 징검다리 건너기, DP, 실버 1
using namespace std;

int getMinEnergy(vector<pair<int, int>> energy, int N, int K){
    vector<vector<int>> dp(N+1, vector<int>(2, 2147483647));
    dp[1][0] = 0;
    dp[1][1] = 0;

    for (int i = 1; i<=N-1 ; ++i) {
        if (i + 1 <= N) {
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + energy[i].first);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + energy[i].first);
        }

        if (i + 2 <= N) {
            dp[i+2][0] = min(dp[i+2][0], dp[i][0] + energy[i].second);
            dp[i+2][1] = min(dp[i+2][1], dp[i][1] + energy[i].second);
        }

        if (i + 3 <= N){
            dp[i+3][1] = min(dp[i+3][1], dp[i][0] + K);
        }
    }

    return min(dp[N][0], dp[N][1]);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin>>N;

    if (N==1){
        cin>>K;
        cout<<0;
    }
    else{
        vector<pair<int, int>> energy(N);
        for (int i = 1; i < N; ++i) {
            cin>>energy[i].first>>energy[i].second;
        }
        cin>>K;

        int minEnergy = getMinEnergy(energy, N, K);
        cout<<minEnergy;
    }

    return 0;
}
