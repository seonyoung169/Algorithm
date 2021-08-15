#include <iostream>
#include <vector>

// BOJ 15988 1,2,3 더하기 3 / DP / 실버 2
using namespace std;

int getDP(int num){
    vector<int> dp(num+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    if (num>=4){
        for (int i = 4; i <= num ; ++i) {
            long long sum = 0;

            for (int j = 1; j <= 3 ; ++j) {
                if (i-j >= 0){
                    sum += dp[i-j];
                } else break;
            }
            dp[i] = sum % 1000000009;
        }
    }

    return dp[num];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    cin>>N;

    for (int i = 0; i < N; ++i) {
        cin>>num;
        cout<<getDP(num)<<'\n';
    }

    return 0;
}
