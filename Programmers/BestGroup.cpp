#include <iostream>
#include <vector>

// 프로그래머스 최고의 집합, level 3 
using namespace std;

vector<int> solution(int n, int s) {
    if(n>s) return {-1};

    if(n==s) {
        vector<int> answer(n, 1);
        return answer;
    }

    int share = s/n;
    int left = s%n;
    vector<int> answer(n, share);

    for(int i=n-1; i>=n-left; i--){
        answer[i]++;
    }

    return answer;
}
