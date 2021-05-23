#include <iostream>
#include <string>

// 프로그래머스 greedy - 큰 수 만들기, level 2
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int start = 0;
    int n = number.size();
    int len = n - k;
    int left = n-k;

    while (k>0 && answer.size() < len) {

        char max = '/';
        int idx = -1;

        for (int i = start; i <= n - left; i++) {
            if (number[i] > max) {
                max = number[i];
                idx = i;
            }
        }

        if (start < idx){
            k -= idx-start;
        }

        start = idx + 1;
        answer += max;
        left--;
    }

    if (answer.size() < len) {
        for (int i = start; i < number.size(); i++) {
            answer += number[i];
        }
    }

    return answer;
}
