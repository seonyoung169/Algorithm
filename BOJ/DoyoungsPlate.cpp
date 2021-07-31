#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

// N개의 숫자 중 조합 구하기
vector<vector<int>> getCombinations(int N){
    vector<vector<int>> combinations;

    vector<int> candidates;  // 0-1-2-3
    for (int i = 0; i < N; ++i) {
        candidates.push_back(i);
    }

    for (int i = 1; i <= N; ++i) {
        // N개 중 i개 뽑을 때
        vector<bool> take(N-i, false);
        for (int j = 0; j < i; ++j) {
            take.push_back(true);
        }

        do {
            vector<int> indexes;
            for (int k = 0; k < N; ++k) {
                if (take[k]) indexes.push_back(candidates[k]);
            }
            combinations.push_back(indexes);
        }while (next_permutation(take.begin(), take.end()));  // 다음 순열이 있으면
    }

    return combinations;
}

int getBestTaste(int N, vector<pair<int, int>> ingredients){
    vector<vector<int>> combinations = getCombinations(N);

    int min = 2147483647;

    for (int i = 0; i < combinations.size(); ++i) {
        int sour = 1, bitter = 0;

        for (int j = 0; j < combinations[i].size(); ++j) {
            int at = combinations[i][j];
            sour *= ingredients[at].first;
            bitter += ingredients[at].second;
        }

        int diff = abs(sour-bitter);
        if (min > diff){
            min = diff;
        }
    }

    return min;
}

int main() {
    int N, S, B;
    vector<pair<int, int>> ingredients;

    cin>>N;
    for (int i = 0; i < N; ++i) {
        cin>>S>>B;
        ingredients.push_back(make_pair(S, B));
    }

    int answer = getBestTaste(N, ingredients);

    cout<<answer;

    return 0;
}
