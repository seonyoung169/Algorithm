#include <iostream>

// BOJ 1789 수들의 합, 이진 탐색 사용
using namespace std;

long long solution(long long S) {
    long long answer;
    long long left = 1, right  = S;

    while (left<=right){
        long long mid = (left+right)/2;
        if (mid*(mid+1)/2 > S) right = mid-1;
        else {
            answer = mid;
            left = mid+1;
        }
    }

    return answer;
}

int main() {
    long long S, ans;

    cin>>S;
    ans = solution(S);

    cout<<ans;

    return 0;
}
