#include <iostream>
#include <string>
#include <vector>

// 프그래머스 가장 긴 팰린드롬, Level 3, DP
using namespace std;

int solution(string s){
    int answer=1, N = s.size();

    vector<vector<int>> dp(N+1, vector<int>(N+1,0));

    // 길이 1
    for (int i = 0; i <N; ++i) dp[i][i] = 1;


    // 길이 2
    for (int i = 0; i < N-1; ++i) {
        if (s[i]==s[i+1]) dp[i][i+1] = 1;
    }

    // 길이 3 이상
    for (int len = 3; len <= N; ++len) {
        int start = 0;
        while (start+len <= N){
            int end = start+len-1;
            if (dp[start+1][end-1] && s[start]==s[end]){
                dp[start][end] = 1;
                answer = max(answer, len);
            }
            start++;
        }
    }

    return answer;
}
