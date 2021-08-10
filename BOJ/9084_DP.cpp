#include <iostream>
#include <vector>

// BOJ 9084 동전, DP, 골드 5,,, 찾아보고 통과함 ㅜㅡㅜ
using namespace std;

int getWayToMake(int M, vector<int> coins){
    vector<int> dp(M+1, 0);
    dp[0] = 1;  // 어떠한 동전도 사용하지 않는 경우 

    for (int i = 0; i < coins.size(); ++i) {
        int coin = coins[i];  
        
        // coin(작은 동전부터)을 마지막에 더해서 j원을 완성하는 경우 탐색 
        for (int j = coin; j <= M ; ++j) {
            dp[j] +=  dp[j-coin];  // j-coin 원을 완성했던 경우에 마지막에 coin을 더하는 경우와 동일 
        }
    }

    return dp[M];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, M;
    cin>>T;
    vector<int> answers;

    for (int i = 0; i < T; ++i) {
        cin>>N;

        vector<int> coins(N, 0);
        for (int j = 0; j < N; ++j) {
            cin>>coins[j];
        }

        cin>>M;
        int ans = getWayToMake(M, coins);
        answers.push_back(ans);
    }


    for (int i = 0; i < T; ++i) {
        cout<<answers[i]<<'\n';
    }
    return 0;
}
