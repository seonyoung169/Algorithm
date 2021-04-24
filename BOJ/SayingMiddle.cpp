#include <iostream>
#include <queue>
#include <vector>

// BOJ 1655 가운데를 말해요, 우선순위 큐 사용, 배열을 절반으로 나누는 것이 핵심!
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int getMiddleNumber(int newNumber){
    int total = maxHeap.size() + minHeap.size();
    int mid = maxHeap.top();
    int trans;

    if (newNumber <= mid) maxHeap.push(newNumber);
    else minHeap.push(newNumber);

    if (maxHeap.size() == minHeap.size()+2){
        trans = maxHeap.top();
        maxHeap.pop();
        minHeap.push(trans);
    }else if(maxHeap.size() +1 == minHeap.size()){
        trans = minHeap.top();
        minHeap.pop();
        maxHeap.push(trans);
    }

    return maxHeap.top();
}

int main() {
    int N;
    cin>>N;

    int num;
    cin>>num;

    vector<int> answer;
    maxHeap.push(num);
    answer.push_back(maxHeap.top());

    for (int i = 0; i < N-1 ; ++i) {
        cin>>num;
        int mid = getMiddleNumber(num);
        answer.push_back(mid);
    }

    for (int i = 0; i < answer.size(); ++i) {
        cout<<answer[i]<<'\n';
    }
    return 0;
}
