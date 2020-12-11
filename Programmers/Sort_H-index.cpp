//프로그래머스 정렬 #3 H-index, 맞음

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b){
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), desc);
    
    //13 12 11 10 
    for(int i=0; i<citations.size(); i++){
        if(i == citations.size()-1){
            if(citations[i] >= i+1){
                answer = i+1;
                break;
            }
        }
        
        // 6 5 3 1 0
        if(citations[i] >= i+1 && citations[i+1] <= i+1){
            if(answer < i+1) answer = i+1;
        }
        
    }

    return answer;
}
