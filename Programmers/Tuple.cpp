#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

// 프로그래머스 튜플, level 2, 2019 카카오 겨울 인턴십
using namespace std;

bool byLength(vector<int> a, vector<int> b){
    return a.size() < b.size();
}
bool byCount(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    int len = s.length();
    s = s.substr(1, len-2);
    len -= 2;

    vector<string> strTokens;
    int left = -1, right = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]=='{') {
            left = i;
            continue;
        }

        if (s[i]=='}'){
            right = i;
            strTokens.push_back(s.substr(left, right-left+1));
        }
    }


    vector<vector<int>> tokens;
    for (int i = 0; i < strTokens.size(); ++i) {
        vector<int> tok;
        strTokens[i] = strTokens[i].substr(1, strTokens[i].size()-2);

        stringstream ss(strTokens[i]);
        string temp;
        while (getline(ss, temp, ',')) {
            tok.push_back(stoi(temp));
        }

        tokens.push_back(tok);
    }
    sort(tokens.begin(), tokens.end(), byLength);

    map<int, int> numberCount;
    for (int i = 0; i < tokens.size(); ++i) {
        for (int j = 0; j < tokens[i].size(); ++j) {
            if (numberCount.find(tokens[i][j]) != numberCount.end()){
                numberCount[tokens[i][j]] += 1;
            }else{
                numberCount.insert(make_pair(tokens[i][j], 1));
            }
        }
    }

    vector<pair<int, int>> counted;
    for(auto pair : numberCount){
        counted.push_back(pair);
    }

    sort(counted.begin(), counted.end(), byCount);

    for(int i=0; i<counted.size(); i++){
        answer.push_back(counted[i].first);
    }

    return answer;
}
