#include <iostream>
#include <vector>
#include <algorithm>

// boj 10815 숫자 카드, 이분탐색 사용, 실버 4
using namespace std;

vector<int> cards;

int binary_search(int number){
    int left = 0, right = cards.size()-1;

    while (left<=right){
        int mid = (left+right)/2;

        if (cards[mid] == number) return true;
        else if (cards[mid]>number) right = mid-1;
        else left = mid+1;
    }

    return false;
}

int main() {
    vector<int> answer;
    int N, M;
    cin>>N;

    cards = vector<int>(N);
    for (int i = 0; i < N; ++i) cin>>cards[i];
    sort(cards.begin(), cards.end());

    cin>>M;
    for (int i = 0; i < M; ++i) {
        int num;
        cin>>num;
        answer.push_back(binary_search(num));
    }

    for (int i = 0; i < M; ++i) {
        cout<<answer[i]<<' ';
    }

    return 0;
}
