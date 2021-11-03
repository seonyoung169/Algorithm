#include <iostream>
#include <vector>

// boj 1912 연속 합, dp, 실버 2
using namespace std;

int getMaxSum(int N, vector<int> numbers){
    int maxSum = numbers[0];

    vector<int> dp(N, -1001);
    dp[0] = numbers[0];

    for (int i = 1; i <= N-1; ++i) {
        dp[i] = max(numbers[i], dp[i-1]+numbers[i]);
        if (dp[i]>maxSum) maxSum = dp[i];
    }

    return maxSum;
}


int main() {

    int N;
    cin>>N;

    vector<int> numbers(N, 0);
    for (int i = 0; i < N; ++i){
        cin>>numbers[i];
    }

    cout<<getMaxSum(N, numbers);

    return 0;
}
