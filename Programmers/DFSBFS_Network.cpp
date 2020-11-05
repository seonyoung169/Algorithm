//프로그래머스 DFSBFS #2 네트워크, 맞음

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int COUNT = 0;

void BFS(int now, vector<vector<int>> & computers, vector<bool> & visited){
    visited[now] = true;

    for(int i=0; i<N; i++){
        if(computers[now][i] == 1 && !visited[i]){
            BFS(i, computers, visited);
        }
    }

}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    N = n;

    for(int i=0; i<N; i++){
        if(!visited[i]){
            COUNT += 1;
            BFS(i, computers, visited);
        }
    }

    answer = COUNT;
    return answer;
}
int main(){

    int ans = solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}});

    cout<<ans;
    return 0;
}
