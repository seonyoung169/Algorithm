#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>

// boj 2467 용액, 투포인터 사용, 골드 5
using namespace std;

vector<long long> numbers;

pair<long long, long long> getBestPair(){
    pair<long long, long long> answer;
    int left = 0, right = numbers.size()-1;
    long long best_sum = LLONG_MAX;

    while (left<right){
        int sum = numbers[left] + numbers[right];

        if (abs(sum) < best_sum){
            best_sum = abs(sum);
            answer.first = numbers[left];
            answer.second = numbers[right];
        }

        if(sum < 0) left++;
        else right--;
    }

    return answer;
}

int main() {
    int N;
    cin>>N;

    numbers.assign(N, 0);
    for (int i = 0; i < N; ++i) cin>>numbers[i];

    pair<long long,long long> answer = getBestPair();
    cout<<answer.first<<" "<<answer.second;

    return 0;
}
