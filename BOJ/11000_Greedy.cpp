#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// boj 11000 강의실 배정, 골드 5, 그리디
using namespace std;

bool byStart(pair<int, int> a, pair<int, int> b){
    return a.first<b.first;
}

int getMinRoom(int N, vector<pair<int, int>> lecture){
    sort(lecture.begin(), lecture.end(), byStart);

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(lecture[0].second);

    for (int i = 1; i < N; ++i) {
        if (pq.top()<=lecture[i].first) pq.pop();
        pq.push(lecture[i].second);
    }

    return pq.size();
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<pair<int, int>> lecture(N, {-1,-1});
    for (int i = 0; i < N; ++i) {
        cin>>lecture[i].first>>lecture[i].second;
    }

    cout<<getMinRoom(N, lecture);


    return 0;
}
