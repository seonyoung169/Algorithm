#include <string>
#include <vector>
#include <queue>

//프로그래머스 힙 - 더 맵게, 맞음!
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int mixcount = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i=0; i<scoville.size(); i++){
        minHeap.push(scoville[i]);
    }
    
    while(!minHeap.empty()){
        if(minHeap.size() == 1){ 
            if(minHeap.top() < K) answer=-1;    // 불가능한 경우
            else answer = mixcount;
            break;
        }else{ //원소가 2개 이상
            if(minHeap.top() >= K){
                answer = mixcount;
                break;
            }
            int first = minHeap.top();
            minHeap.pop();
            int second = minHeap.top();
            minHeap.pop();
        
            int mixed = first + 2*second;
            minHeap.push(mixed);
            mixcount++;
        }
    }
    
    return answer;
}
