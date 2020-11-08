//프로그래머스 DFSBFS#3 단어 변환, 맞음

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> visited(51, false);
int STAGES = -1;

bool targetExist(vector<string> words, string target){
    for(int i=0; i<words.size(); i++){
        if(words[i] == target) return true;
    }
    return false;
}

int countLetters(string word1, string word2){
    int cnt = 0;
    for(int i=0; i<word1.length(); i++){
        if(word1[i] != word2[i]) cnt++;
        if(cnt > 1) return 100;
    }
    return cnt;
}
void DFS(int before, int now, string target, vector<string> words, int count){
    if(visited[now+1]) return;
    if(words[now] == target) { //target 단어를 찾으면 return
        if(STAGES == -1) {
            STAGES = count;
        }else{
            if(STAGES > count){
                STAGES = count;
            }
        }
        return;
    }

    visited[now+1] = true;

    for(int i=0; i<words.size(); i++){
        if(i==now) continue;

        if(!visited[i+1] &&
           countLetters(words[i], words[now]) == 1){ //1글자만 다르면 재귀호출
            DFS(now, i, target, words, count+1);
            if(before!=-1) visited[before+1] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    if(!targetExist(words, target)) return answer;  //타켓 단어가 존재하는지 확인

    for(int i=0; i<words.size(); i++){
        if(countLetters(begin, words[i])== 1){
            DFS(-1, i, target, words, 1);
        }
    }

    if(STAGES == -1) answer=0;
    else answer = STAGES;

    return answer;
}
