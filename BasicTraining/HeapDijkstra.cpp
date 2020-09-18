#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 1000000000;

vector<pair<int,int>> a[7];  //간선 정보
int d[7]; //최소 비용 저장 배열

void dijkstra(int start){
    d[start] = 0;
    priority_queue<pair<int,int>> pq;  //힙 구조

    while (!pq.empty()){
        int current = pq.top().first;  //큐의 최 상단에는 가장 적은 비용을 가지는 노드 저장
        int distance = -pq.top().second;
        pq.pop();

        if(d[current] < distance) continue;

        for(int i=0; i<a[current].size(); i++){
            int next = a[current][i].first;
            int nextDistance = distance + a[current][i].second;

            if(nextDistance < d[next]){
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }
    }
}

int main(){
    for(int i=0; i<number; i++){
        d[i] = INF;
    }

    a[1].push_back(make_pair(2, -2));
}
