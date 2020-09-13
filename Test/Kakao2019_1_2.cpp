#include <iostream>
#include <vector>
#include <algorithm>

//2019 카카오 공채 1차 2번 실패율 문제, 맞음!
using namespace std;

bool compare(pair<int, float>a, pair<int, float>b) {
    if(a.second != b.second){
        return a.second > b.second;
    } else{
        return a.first < b.first;
    }
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> count(N+2, 0);
    vector<pair<int, float>> failure;

    for(int i=0; i<stages.size(); i++){
        count[stages.at(i)] += 1;
    }

    for(int i=1; i<count.size()-1; i++){
        int players = stages.size();
        for(int j=1; j < i; j++){
            players -= count.at(j);
        }

        if(players != 0){
            failure.push_back(make_pair(i, (float)count.at(i)/(float)players));
        }
    }

    sort(failure.begin(), failure.end(), compare);

    int temp = failure.size();
    for(int i=0; i<temp; i++){
        answer.push_back(failure[i].first);
    }
    for(int i=temp+1; i<= N; i++){
        answer.push_back(i);
    }
    return answer;
}
int main(){
    vector<int> answer = solution(5, {2, 1, 2, 6, 2, 4, 3, 3});

    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<' ';
    }
    cout<<'\n';

    return 0;
}
