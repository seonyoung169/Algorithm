#include <iostream>
#include <vector>

//프로그래머스 스택/큐 - 주식 가격, 맞음 근데 좀 아쉬운 풀이,,
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for(int turn=0; turn<=prices.size()-2; turn++){
        int stock = prices[turn];
        int count = 0;
        int compare;
        for(compare=turn+1; compare<prices.size(); compare++){
            if(prices[compare] < stock){
                count++;
                break;
            }else {
                count++;
            }
        }
        answer.push_back(count);
    }
    answer.push_back(0);

    return answer;
}
