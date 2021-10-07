#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>

// boj 2467 용액, 이진탐색, 골드 5
using namespace std;

vector<long long> numbers;

pair<long long, long long> getBestPair(){
    pair<long long, long long> answer;
    long long best_sum = LLONG_MAX;

    for(int i=0; i<numbers.size()-1; i++){
        int flag = numbers[i];
        int left = i+1, right = numbers.size()-1;

        while (left<=right){
            int mid = (left+right)/2;
            int sum = flag + numbers[mid];

            if (best_sum > abs(sum)){
                best_sum = abs(sum);
                answer.first = numbers[i];
                answer.second = numbers[mid];
            }

            if (sum<0) left = mid+1;
            else right = mid-1;
        }
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
