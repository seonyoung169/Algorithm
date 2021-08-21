#include <iostream>
#include <vector>
#include <algorithm>

// BOJ 13902 개업 2, 골드 3, DP 사용,, 맞긴 맞았는데,,, ㅋ
using namespace std;

vector<int> wok;

vector<int> makeCombi(int N, int M){
    vector<int> volumes;

    vector<bool> selected(N+1, false);
    for (int i = 0; i < M; ++i) {
        selected[wok[i]] = true;
    }

    for (int i = 0; i < M; ++i) {
        for (int j = i+1; j < M; ++j) {
            int sum = wok[i] + wok[j];
            if(sum <= N && !selected[sum]) {
                selected[sum] = true;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (selected[i]) volumes.push_back(i);
    }

    return volumes;
}

int getMinCook(vector<int> volume, int N){
    vector<int> dp(N+1, -1);
    dp[0] = 0;

    for (int i = 0; i < volume.size(); ++i) {
        int vol = volume[i];
        dp[vol] = 1;
        for (int j = vol+1; j <= N ; ++j) {
            if (dp[j-vol] == -1) continue;
            if (dp[j] == -1 || dp[j-vol] + 1 < dp[j]){
                dp[j] = dp[j-vol] + 1;
            }
        }
    }

    return dp[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin>>N>>M;

    wok.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin>>wok[i];
    }

    vector<int> volume = makeCombi(N, M);

    int answer = getMinCook(volume, N);
    cout<<answer;

    return 0;
}
