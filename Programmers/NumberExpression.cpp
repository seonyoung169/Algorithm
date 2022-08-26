#include <iostream>
#include <string>
#include <vector>

// programmers 숫자의 표현, level 2

using namespace std;

int solution(int n) {
    int answer = 1;
    int K = 2;

    while (true) {
        int sum = 0;
        for (int i = 0; i < K; ++i) sum += i;

        if(n<=sum) break;

        if (((n-sum)/K)>0 && ((n-sum)%K == 0)) {
            answer += 1;
        }

        K++;
    }

    return answer;
}
