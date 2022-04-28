#include <iostream>
#include <vector>

// 프로그래머스 멀리뛰기 
using namespace std;

long long solution(int n) {
    long long dp[2001];
    dp[1] = 1;
    dp[2] = 2;

    if(n<=2) return dp[n];

    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }

    return dp[n];
}
