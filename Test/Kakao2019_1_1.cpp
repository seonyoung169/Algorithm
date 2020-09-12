#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <map>

//2019 카카오 공채 1차 1번, 맞음! (map 이용)
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> recordTokens(record.size());
    map<string, string> nameInfo;

    //input 정보 잘라서 vector에 저장, recordTokens 완성
    for(int i=0; i<record.size(); i++){
        char * cstring = new char[1000];
        strcpy(cstring, record.at(i).c_str());

        char * tok = strtok(cstring, " ");

        while (tok != nullptr){
            recordTokens[i].push_back(string(tok));
            tok = strtok(nullptr, " ");
        }

        if(recordTokens[i][0] == "Enter" || recordTokens[i][0] == "Change") {
            if (i == 0) {
                nameInfo.insert(make_pair(recordTokens[i][1], recordTokens[i][2]));
            } else {
                if (nameInfo.find(recordTokens[i][1]) != nameInfo.end()) {  //존재하는 uid 이면 닉네임 수정
                    nameInfo.at(recordTokens[i][1]) = recordTokens[i][2];
                } else {
                    nameInfo.insert(make_pair(recordTokens[i][1], recordTokens[i][2]));
                }
            }
        }
    }

    for(int i=0; i<recordTokens.size(); i++){
        if(recordTokens[i][0] == "Enter"){
            answer.push_back((nameInfo.find(recordTokens[i][1])->second) + "님이 들어왔습니다.");
        }
        if(recordTokens[i][0] == "Leave"){
            answer.push_back((nameInfo.find(recordTokens[i][1])->second) + "님이 나갔습니다.");
        }
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<string> answer = solution({"Enter uid1234 Muzi", "Enter uid4567 Prodo",
                                      "Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"});

    for(int i=0 ;i<answer.size(); i++){
        cout<<answer.at(i)<<'\n';
    }
    return 0;
}
