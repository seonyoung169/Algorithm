#include <iostream>
#include <vector>
#include <algorithm>

//boj 2407 조합, dp, 실버 3
using namespace std;

string dp[101][101];

string makeStringSum(string a, string b){
    int sum = 0;
    string answer = "";

    while (!a.empty() || !b.empty() || sum!=0) {
        if (!a.empty()){
            sum += a.back()-'0';
            a.pop_back();
        }

        if (!b.empty()){
            sum += b.back()-'0';
            b.pop_back();
        }

        answer.push_back((sum%10)+'0');
        sum = sum/10;
    }

    reverse(answer.begin(), answer.end());
    return answer;
}

string combination(int n, int r){
    if (n==r || r==0) return "1";
    if (dp[n][r] != "") return dp[n][r];

    dp[n][r] = makeStringSum(combination(n-1, r-1), combination(n-1, r));

    return dp[n][r];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin>>N>>M;

    cout<<combination(N, M);

    return 0;
}
