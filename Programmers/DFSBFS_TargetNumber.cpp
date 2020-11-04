//프로그래머스 DFSBFS #1 타겟넘버, 맞음

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int TARGET;
int solutionCnt = 0;

void BFS(vector<int> numbers, int index, int now){
    if(index == numbers.size()-1){
        if(now  == TARGET){
            solutionCnt++;
            return;
        }
    }

    if(index < numbers.size()-1){
        BFS(numbers, index+1,  now + numbers[index+1]);
        BFS(numbers, index+1,  now - numbers[index+1]);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    TARGET = target;

    BFS(numbers, 0, numbers[0]);
    BFS(numbers, 0, -numbers[0]);

    answer = solutionCnt;

    return answer;
}
int main() {

    int ans = solution({1,1,1,1,1}, 3);
    cout<<ans<<'\n';

    return 0;
}
