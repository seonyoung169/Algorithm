#include <iostream>
#include <vector>
#include <algorithm>

// 프로그래머스 이진 탐색, 입국 심사, level 3
using namespace std;

long long solution(int n, vector<int> times) {

    sort(times.begin(), times.end());

    unsigned long long left = 1;
    unsigned long long right = n*(times[times.size()-1]);
    unsigned long long mid;
    unsigned long long answer = right;

    while (left<=right){  // 최소가 최대를 추월할 때 까지 탐색
        unsigned long long count = 0;
        mid = (left+right)/2;

        // mid 시간 동안 몇명을 검사할 수 있는지 계산 count
        for (unsigned long long i = 0; i < times.size(); ++i) {
            count += mid/times[i];
        }

        if (count >= n){
            if (mid <= answer){
                // 해당 시점의 mid 값을 임시 정답으로 저장, 최소의 mid를 탐색
                answer = mid;
            }
            right = mid-1;
        }else {
            left = mid+1;
        }
    }

    return answer;
}
