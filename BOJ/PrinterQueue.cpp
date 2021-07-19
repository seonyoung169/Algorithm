#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

// BOJ 21608 프린터 큐
using namespace std;

bool desc(int a, int b){
    return a>b;
}
int getPrintingOrder(int M, queue<pair<int, int>> files, vector<int> priorities) {
    int printed = 0;
    int idx = 0;

    while (!files.empty()){
        int num = files.front().first;
        int prior = files.front().second;

        if (prior == priorities[idx]) {
            files.pop();
            idx++;
            printed++;
            if (num == M) break;
        }else{
            pair<int, int> file = files.front();
            files.pop();
            files.push(file);
        }
    }

    return printed;
}

int main() {
    int T, N, M, priority;

    vector<int> orders;

    cin>>T;
    for (int i = 0; i < T; ++i) {
       cin>>N>>M;
        queue<pair<int, int>> files;
        vector<int> priorities;

       for (int j = 0; j < N; ++j) {
            cin>>priority;
           priorities.push_back(priority);
            files.push(make_pair(j, priority));
       }
       sort(priorities.begin(), priorities.end(), desc);

       int ans = getPrintingOrder(M, files, priorities);
       orders.push_back(ans);
    }

    for (int i = 0; i < orders.size() ; ++i) {
        cout<<orders[i]<<'\n';
    }


    return 0;
}
