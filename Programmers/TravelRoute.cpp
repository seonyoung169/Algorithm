#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 프로그래머스 힙 - 여행경로, level3, 맞음!
using namespace std;

bool found = false;

void searchRoute(string location, vector<vector<string>> & tickets, vector<bool> & used, vector<string> & answer, int & count){
    answer.push_back(location);

    if(count ==  tickets.size()){
        for(int i=0; i<tickets.size(); i++){
            if(tickets[i][0] == location && !used[i]){
                answer.push_back(tickets[i][1]);
                found = true;
                return;
            }
        }
    }

    for(int i=0; i<tickets.size(); i++){
        if(tickets[i][0] == location && !used[i]){
            string transfer = tickets[i][1];
            used[i] = true;
            count++;
            searchRoute(transfer, tickets, used, answer, count);
            if(!found) {
                used[i] = false;
                continue;
            }else{
                return;
            }
        }
    }
    answer.pop_back();
    count--;
    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> used(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    int count = 1;
    searchRoute("ICN", tickets,  used, answer, count);

    return answer;
}

int main() {
    vector<string> answer;

    answer = solution({{"ICN", "COO"}, {"ICN", "BOO"}, {"COO", "ICN"}, {"BOO", "DOO"}});

    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<'\n';
    }
    return 0;
}
