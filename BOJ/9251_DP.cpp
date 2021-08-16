#include <iostream>
#include <vector>
#include <string>

// BOJ 9251 LCS, DP, 골드 5
using namespace std;

int getLCS(string str1, string str2){
    int N = str1.length(), M = str2.size();
    vector<vector<int>> dp(N+1, vector<int>(M+1, 0));

    for (int i = 1; i <=N ; ++i) {
        for (int j = 1; j<=M; j++){
            if (str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[N][M];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1, str2;
    cin>>str1>>str2;

    int longest = getLCS(str1, str2);
    cout<<longest;

    return 0;
}
