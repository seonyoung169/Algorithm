#include <iostream>
#include <vector>
#include <cmath>

// boj 17262 Four Squares, 완탐, dp, 실버 3
using namespace std;

int main() {
    int N;
    cin>>N;

    vector<int> dp(N+1, 0);
    dp[1] = 1;

    for (int i = 2; i <= N; ++i) {
        if (sqrt(i) == (int)sqrt(i)) {
            dp[i] = 1;
        } else {
            int min = 50000, temp;
            for (int j = 1; j * j < i; ++j) {
                if (min > dp[i - (j*j)]){
                    min = dp[i - (j*j)];
                    temp = j;
                }
            }

            dp[i] = dp[i-(temp*temp)] + 1;
        }
    }

    cout<<dp[N];

    return 0;
}
