//프로그래머스 해시 #1 완주하지 못한 선수, 맞음

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int i;
    for(i=0; i<completion.size(); i++){
        if(participant[i] != completion[i]){
            answer = participant[i];
            break;
        }
    }

    if(answer == ""){
        answer = participant[i];
    }
    return answer;
}
int main(){

    string ans = solution({"marina", "josipa", "nikola", "vinko", "filipa"}, { "josipa", "filipa", "marina", "nikola"});
    //string ans = solution({"mislav", "stanko", "mislav", "ana"}, { "stanko", "mislav", "ana"});
    cout<<ans<<'\n';

    return 0;
}
