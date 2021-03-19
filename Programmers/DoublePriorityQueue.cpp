#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

//프로그래머스 힙 - 이중 우선순위 큐, level3, 맞음
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> remains, duplicated;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int numberCount = 0;

    for(int i=0; i<operations.size(); i++){
        int num = stoi(operations[i].substr(2, operations[i].size()-2));
        if(operations[i][0]=='I'){  //insert
            if(numberCount == 0){
                maxHeap = priority_queue<int>();
                minHeap = priority_queue<int, vector<int>, greater<int>>();
            }
            maxHeap.push(num);
            minHeap.push(num);
            numberCount++;
        }else{  //pop
            if (numberCount>0){
                if (num==1){
                    maxHeap.pop();
                    numberCount--;
                }else{
                    minHeap.pop();
                    numberCount--;
                }
            }
        }
    }

    while (!maxHeap.empty()){
        remains.push_back(maxHeap.top());
        maxHeap.pop();
    }

    while (!minHeap.empty()){
        remains.push_back(minHeap.top());
        minHeap.pop();
    }

    sort(remains.begin(), remains.end());

    if(remains.size()>=2){
        for(int i=1; i<remains.size(); i++){
            if(remains[i]==remains[i-1]){
                duplicated.push_back(remains[i]);
            }
        }
    }

    if(duplicated.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(duplicated[duplicated.size()-1]);
        answer.push_back(duplicated[0]);
    }

    return answer;
}

int main() {
    vector<int> answer;

    answer = solution({"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"});

    cout<<answer[0]<<' '<<answer[1]<<'\n';

    return 0;
}
