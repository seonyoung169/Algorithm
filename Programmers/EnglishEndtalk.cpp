

#include <set>
#include <string>
#include <vector>
#include <iostream>

// 프로그래머스 영어 끝말잇기, level 2
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    
    set<string> voca;
    voca.insert(words[0]);
    
    for(int i=1; i<words.size(); i++){
        char last = words[i-1][words[i-1].size()-1];
        char start = words[i][0];
        
        if(voca.find(words[i]) != voca.end() 
           || last != start){
            answer[0] = (i+1) % n;
            if(answer[0] == 0) answer[0] = n;
            answer[1] = (i/n) + 1;
            break;
        }
        
        voca.insert(words[i]);
    }
    

    return answer;
}
