#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool byDeadLine(pair<int, int> a, pair<int, int> b){
    if (a.second == b.second){
        return a.first>b.first;
    }else{
        return a.second > b.second;
    }
}

int getLatestTime(int N, vector<pair<int, int>> task){
    sort(task.begin(), task.end(), byDeadLine);

    int limit = task[0].second;
    for (int i = 0; i < N; ++i) {
        if (limit > task[i].second){
            limit = task[i].second;
        }
        limit -= task[i].first;
    }

    return limit;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int need=-1, deadline=-1;
    vector<pair<int, int>> task;
    for (int i = 0; i < N; ++i) {
        cin>>need>>deadline;
        task.push_back(make_pair(need, deadline));
    }

    int wakeup = getLatestTime(N, task);
    if (wakeup < 0) wakeup = -1;

    cout<<wakeup;

    return 0;
}
