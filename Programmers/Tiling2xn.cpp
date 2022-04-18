#include <string>
#include <vector>

// 프로그래머스 2xn 타일링, level 3, dp
using namespace std;


int solution(int n) {
    vector<int> dp(n+1, 0);
    dp[1] = 1, dp[2] = 2;
    
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
    }
    
    return dp[n];
}
