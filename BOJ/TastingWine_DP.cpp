#include <iostream>
#include <vector>
#include <algorithm>

//BOJ 2156 포도주 시식, DP 사용, 맞음!
using namespace std;

vector<int> dp(10001, -1);
vector<int> winebar;

int main() {
    int N, drink, sumMax;
    cin>>N;

    winebar.push_back(-1);
    for(int i=0; i<N; i++){
        cin>>drink;
        winebar.push_back(drink);
    }

    dp[1] = winebar[1];
    dp[2] = winebar[1]+winebar[2];
    sumMax = dp[2];

    dp[3] = max(winebar[1], winebar[2]) + winebar[3];
    if(sumMax < dp[3]) sumMax = dp[3];

    dp[4] = max(dp[1]+winebar[3]+winebar[4],
                dp[2]+winebar[4]);
    if(sumMax <dp[4]) sumMax = dp[4];

    for(int i=5; i<=N; i++){
        dp[i] = max(dp[i-3]+winebar[i-1]+winebar[i],
                    dp[i-2]+winebar[i]);
        dp[i] = max(dp[i], dp[i-4] + winebar[i-1] + winebar[i]);

        if(sumMax < dp[i]) sumMax = dp[i];
    }

    cout<<sumMax<<'\n';

    return 0;
}
