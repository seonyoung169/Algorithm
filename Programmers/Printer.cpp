#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// 프로그래머스 level 2 프린터, 맞음!

bool desc(int a, int b){
    return a>b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> sorted = priorities;
    queue<pair<int, int>> q;

    sort(sorted.begin(), sorted.end(), desc);

    for(int i=0; i<priorities.size(); i++){
        pair<int, int> p = make_pair(i, priorities[i]);
        q.push(p);
    }


    while (!q.empty()){
        if (!(q.front().second < sorted[0])){  // print
            answer++;
            if (q.front().first == location){
                break;
            }else{
                q.pop();
                sorted.erase(sorted.begin());
            }
        }else{  // not print, go back again
            pair<int, int> front = q.front();
            q.pop();
            q.push(front);
        }
    }

    return answer;
}

int main() {
    int answer;

    answer= solution({1, 1, 9, 1, 1, 1}, 0);

    cout<<answer<<'\n';

    return 0;
}
