#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

// boj 5568 카드 놓기, 완전 탐색, 실버 4
using namespace std;

set<int> numbers;

void makeNumbers(vector<int> candidates){

    do {
        string permuted = "";
        for (int i = 0; i < candidates.size(); ++i) {
            permuted += to_string(candidates[i]);
        }

        int converted = stoi(permuted);
        numbers.insert(converted);

    }while (next_permutation(candidates.begin(), candidates.end()));

}

int main() {
    int N,K;
    cin>>N>>K;

    vector<int> cards(N, 0);

    for (int i = 0; i < N; ++i) cin>>cards[i];
    sort(cards.begin(), cards.end());


    vector<bool> flag(N-K, false);
    for (int i = 0; i < K; ++i) flag.push_back(true);

    do {
        vector<int> candidates;
        for (int i = 0; i < N; ++i) {
            if (flag[i]) candidates.push_back(cards[i]);
        }
        makeNumbers(candidates);
    }while (next_permutation(flag.begin(), flag.end()));

    cout<<numbers.size()<<'\n';

    return 0;
}
