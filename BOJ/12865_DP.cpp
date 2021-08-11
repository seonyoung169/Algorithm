#include <iostream>
#include <vector>

// BOJ 12865 평범한 배낭, DP
using namespace std;


int getMaxValue(vector<pair<int, int>> items, int K){
    vector<vector<int>> dp(items.size(), vector<int>(K+1));

    for (int i = 0; i <= K ; ++i) {
        dp[0][i] = 0;
    }

    for (int i = 1; i < items.size(); ++i) {
        // 배낭 전체 무게가 해당 아이템보다 작을 때는 기존의 dp 값 유지
        for (int j = 0; j < items[i].first; ++j) { 
            dp[i][j] = dp[i-1][j];
        }

        // i번째 아이템을 사용할 때와 사용하지 않았을 때 가치의 최댓값으로 dp 완성
        for (int j = items[i].first; j <= K ; ++j) {  
            int left = j - items[i].first;
            dp[i][j] = max(dp[i-1][j], dp[i-1][left] + items[i].second);
        }
    }

    return dp[items.size()-1][K];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin>>N>>K;
    vector<pair<int, int>> items(N+1, make_pair(0,0));

    for (int i = 1; i <= N; ++i) {
        cin>>items[i].first;
        cin>>items[i].second;
    }

    int value = getMaxValue(items, K);

    cout<<value;

    return 0;
}
