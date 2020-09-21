#include <iostream>
#include <vector>
#include <queue>

//BOJ 11779 최소 비용 구하기 2, 다익스트라, 런타임에러 왠지 존나 모르겠음~!~!~
using namespace std;

int INF = 1000000000;

void dijkstra(vector<vector<pair<int, int>>> & graph, vector<int> & cost, vector<int> & trace, int start, int end){

    cost[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()){
        int current = pq.top().second;
        int currentcost = -pq.top().first;
        pq.pop();

        if(cost[current] < currentcost) continue;

        for(int i=0; i<graph[current].size(); i++){
            int nextnode = graph[current][i].first;
            int nextcost = currentcost + graph[current][i].second;

            if(cost[nextnode] >= nextcost){
                cost[nextnode] = nextcost;
                trace[nextnode] = current;
                pq.push(make_pair(-nextcost,nextnode));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, a, b, c;
    int start, end;

    cin>>N>>M;
    vector<vector<pair<int, int>>> graph(N+1); //간선 정보 저장용
    int test = graph.size();
    vector<int> cost(N+1);
    vector<int> result;
    vector<int> trace(N+1);

    for(int i=0; i<=M; i++){
        cost[i] = INF;
    }

    for(int j=0; j<M; j++){
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
    }
    cin>>start>>end;
    int milestone = end;

    dijkstra(graph, cost, trace, start, end);

    result.push_back(milestone);
    while (milestone!=start){
        result.push_back(trace[milestone]);
        milestone = trace[milestone];
    }

    cout<<cost[end]<<'\n'<<result.size()<<'\n';
    for(int k = result.size()-1; k>=0; k--){
        cout<<result[k]<<' ';
    }
    cout<<'\n';

    return 0;
}
