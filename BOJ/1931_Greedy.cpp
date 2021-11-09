#include <iostream>
#include <vector>
#include <algorithm>

// boj 1931 회의실 배정, 실버 2, 그리디
using namespace std;

bool byEnd(pair<int, int> a, pair<int, int> b){  // 강의 시작 시간 기준 오름 차순 정렬
    if (a.second==b.second) return a.first<b.first;
    return a.second < b.second;
}

int getMaxMeeting(int N, vector<pair<int, int>> meeting){
    sort(meeting.begin(), meeting.end(), byEnd);

    int max_meeting = 1, i = 1;
    int endTime = meeting[0].second;

    while (i<N){
        if (endTime <= meeting[i].first){
            max_meeting++;
            endTime = meeting[i].second;
        }
        i++;
    }

    return max_meeting;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<pair<int, int>> meeting(N, {-1,-1});
    for (int i = 0; i < N; ++i) {
        cin>>meeting[i].first>>meeting[i].second;
    }

    cout<<getMaxMeeting(N, meeting);

    return 0;
}
