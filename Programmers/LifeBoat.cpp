#include <string>
#include <vector>
#include <algorithm>

// 프로그래머스 그리디 - 구명보트, level 2
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int front = 0, back = people.size()-1;
    
    sort(people.begin(), people.end());
    
    while(front <= back){
        if (front == back){
            answer++;
            break;
        }
        
        if(people[front] + people[back] <= limit){
            answer++;
            front++;
            back--;
        }else{
            answer++;
            back--;
        }
    }

    return answer;
}
