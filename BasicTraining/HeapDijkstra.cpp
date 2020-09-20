#include <iostream>
#include <vector>
#include <queue>

//우선순위 큐()를 이용한 다익스트라 알고리즘힙, O(N log N)
using namespace std;

int number = 6;
int INF = 1000000000;

vector<pair<int, int>> a[7]; //간선 정보 저장용
int d[7]; //최소 비용

void dijkstra(int start){
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(start, 0));

    while(!pq.empty()){
        int current = pq.top().first;
        int distance = -pq.top().second;

        pq.pop();
        if(d[current] < distance) continue;

        for(int i=0; i<a[current].size(); i++){
            int next = a[current][i].first;
            int nextdistance = distance + a[current][i].second;

            if(d[next] > nextdistance){
                d[next] = nextdistance;
                pq.push(make_pair(next, -nextdistance));
            }
        }
    }
}

int main(){
    for(int i=1; i<=6; i++){
        d[i] = INF;
    }

    a[1].push_back(make_pair(2,2));
    a[1].push_back(make_pair(3,5));
    a[1].push_back(make_pair(4,1));

    a[2].push_back(make_pair(1,2));
    a[2].push_back(make_pair(3,3));
    a[2].push_back(make_pair(4,2));

    a[3].push_back(make_pair(1,5));
    a[3].push_back(make_pair(2,3));
    a[3].push_back(make_pair(4,3));
    a[3].push_back(make_pair(5,1));
    a[3].push_back(make_pair(6,5));

    a[4].push_back(make_pair(1,1));
    a[4].push_back(make_pair(2,2));
    a[4].push_back(make_pair(3,3));
    a[4].push_back(make_pair(5,1));

    a[5].push_back(make_pair(3,1));
    a[5].push_back(make_pair(4,1));
    a[5].push_back(make_pair(6,2));

    a[6].push_back(make_pair(3,5));
    a[6].push_back(make_pair(5,2));

    dijkstra(1);

    for(int i=1; i<=6; i++){
        cout<<d[i]<<' ';
    }
    cout<<'\n';

    return 0;
}
