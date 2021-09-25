#include <iostream>
#include <vector>
#include <queue>

// boj 13549 숨바꼭질 3, 골드 5, bfs
using namespace std;

int bfs(int N, int K){
    if(N==K) return 0;

    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));

    vector<bool> visited(100001, false);
    visited[N] = true;

    while (!q.empty()){
        int curr = q.front().first;
        int sec = q.front().second;

        if (curr == K){
            return sec;
        }
        q.pop();

        if (curr*2 <= 100000 && !visited[curr*2]){
            visited[curr*2] = true;
            q.push(make_pair(2*curr, sec));
        }

        if (curr-1 >= 0 && !visited[curr-1]){
            visited[curr-1] = true;
            q.push(make_pair(curr-1, sec+1));
        }

        if (curr+1 <= 100000 && !visited[curr+1]){
            visited[curr+1] = true;
            q.push(make_pair(curr+1, sec+1));
        }
    }
}

int main() {
    int N,K;
    cin>>N>>K;

    cout<<bfs(N, K);

    return 0;
}
