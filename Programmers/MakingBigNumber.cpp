#4

#include <iostream>
#include <string>

// 프로그래머스 큰 수 만들기, 그리디, level 2 

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int N = number.size();
    int need = N-k;
    
    int from = 0, to = k;
    
    while (need>0 && from<to) {
        char max = '/';
        int idx = -1;
        
        for(int i=from; i<=to; i++){
            if(number[i] > max) {
                max = number[i];
                idx = i;
            }
            
            if(max=='9') {
                break;
            }
        }
        
        answer += max;
        need--;
        from = idx + 1;
        to = N-need;
    }
    
    if(answer.size() < N-k) {
        for(int i=from; i<N; i++){
            answer += number[i];
        }
    }
    
    return answer;
}
