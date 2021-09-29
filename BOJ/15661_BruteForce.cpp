#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stdlib.h>

// boj 15661 링크와 스타트, brute force, 실버 1
using namespace std;

vector<pair<vector<int>, vector<int>>> getCombination(int N, int R){
    vector<pair<vector<int>, vector<int>>> result;

    vector<bool> select(N-R, false);
    for (int i = 0; i < R; ++i) select.push_back(true);

    do {
        vector<int> link;
        vector<int> start;
        for (int i = 0; i < N; ++i) {
            if (select[i]) link.push_back(i+1);
            else start.push_back(i+1);
        }
        result.push_back({link, start});
    }while (next_permutation(select.begin(), select.end()));

    return result;
}

int calStrength(vector<int> team, vector<vector<int>> S){
    int strength = 0;
    for (int i = 0; i < team.size()-1; ++i) {
        for (int j = i+1; j < team.size() ; ++j) {
            int r = team[i], c = team[j];
            strength += S[r-1][c-1];
            strength += S[c-1][r-1];
        }
    }

    return strength;
}

int minDiff(int N, vector<vector<int>> S){
    int min = INT_MAX;

    for (int r = 1; r <= N/2 ; ++r) {
        vector<pair<vector<int>, vector<int>>> combination = getCombination(N, r);
        for (int i = 0; i < combination.size(); ++i) {
            int strength_link, strength_start;

            if (combination[i].first.size() == 1) strength_link = 0;
            else strength_link = calStrength(combination[i].first, S);

            if (combination[i].second.size() == 1) strength_start = 0;
            else strength_start = calStrength(combination[i].second, S);

            int diff = abs(strength_link - strength_start);

            if (min > diff) min = diff;
        }
    }

    return min;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<vector<int>> S(N, vector<int>(N, -1));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>S[i][j];
        }
    }

    cout<<minDiff(N, S);

    return 0;
}
