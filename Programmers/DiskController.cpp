#include <vector>
#include <queue>
#include <algorithm>

// 프로그래머스 힙 - Level3 디스크 컨트롤러, 맞음!!! 하ㅜ 연습 좀 해라,,
using namespace std;

struct compare{
    bool operator()(pair<int, int>a, pair<int, int>b){
        return a.second > b.second;
    }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0, sec = 0;
    int nextTurn = 1;
    pair<int, int> nowTask;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

    sort(jobs.begin(), jobs.end());  // jobs 요청된 시간 순으로 정

    pq.push(make_pair(jobs[0][0], jobs[0][1]));

    while(!pq.empty()) {
        nowTask = pq.top();
        pq.pop();
        if(sec < nowTask.first){
            sec = nowTask.first;
        }
        sec += nowTask.second;
        answer += sec - nowTask.first;

        for (int i = nextTurn; i < jobs.size() ; ++i) {
            if(jobs[i][0] <= sec){
                pq.push(make_pair(jobs[i][0], jobs[i][1]));
                nextTurn++;
            }else{
                break;
            }
        }

        if(pq.empty() && nextTurn<jobs.size()){
            pq.push(make_pair(jobs[nextTurn][0], jobs[nextTurn][1]));
            nextTurn++;
        }
    }

    return answer / jobs.size();
}
