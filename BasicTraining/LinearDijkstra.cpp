#include <iostream>

//다익스트라 기본 알고리즘, 선형 탐색 이용 O(N^N)
using namespace std;

int Distance[6]; // 최단 거리 저장 배열
int number = 6;
int INF = 1000000000;
bool visited[6];

int a[6][6]={
        {0,2,5,1,INF,INF},
        {2,0,3,2,INF,INF},
        {5,3,0,3,1,5},
        {1,2,3,0,1,INF},
        {INF,INF,1,1,0,2},
        {INF,INF,5,INF,2,0}
};

//가장 최소 거리를 가지는 정점 반환
int getMinIndex(){
    int min = INF;
    int index;

    for(int i=0; i<number; i++){
        if(Distance[i] < min && !visited[i]){
            min = Distance[i];
            index = i;
        }
    }
    return index;
}

//다익스트라를 수행하는 함수
void dijkstra(int start){
    for(int i=0; i<number; i++){
        Distance[i] = a[start][i];
    }
    visited[start] = true;

    for(int i=0; i<number-2; i++) {
        int current = getMinIndex();
        visited[current] = true;

        for (int j = 0; j < 6; j++) {
            if (!visited[j]) {
                if (Distance[current] + a[current][j] < Distance[j]) {
                    Distance[j] = Distance[current] + a[current][j];
                }
            }
        }
    }
}
int main(){

    dijkstra(0);
    for(int i=0; i<number;i++){
        cout<<Distance[i]<<' ';
    }
    cout<<'\n';

    return 0;
}
