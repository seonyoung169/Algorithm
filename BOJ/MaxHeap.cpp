#include <iostream>
#include <queue>

// BOJ 11279 최대 힙, 우선순위 큐 STL 이용, 시간초과 주의
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, num;
    cin>>N;

    priority_queue<int> q;

    for (int i = 0; i < N ; ++i) {
        cin>>num;
        if (num == 0){
            if (q.empty()) cout<<0<<'\n';
            else{
                cout<<q.top()<<'\n';
                q.pop();
            }
            continue;
        }

        if (num > 0) q.push(num);
    }

    return 0;
}
