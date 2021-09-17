#include <string>
#include <vector>
#include <iostream>
#include <sstream>

// 프로그래머스 추석 트래픽, level 3
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    int max = 24 * 3600;
    vector<pair<long long, long long>> traffics;

    for(int i=0; i<lines.size(); i++){
        vector<string> tokens;
        stringstream ss1(lines[i]);
        string temp;

        while(getline(ss1, temp, ' ')){
            tokens.push_back(temp);
        }

        vector<string> frags;
        stringstream ss2(tokens[1]);

        while(getline(ss2, temp, ':')){
            frags.push_back(temp);
        }

        long long endTime = 0;
        endTime += stoi(frags[0]) * 3600 * 1000;
        endTime += stoi(frags[1]) * 60 * 1000;
        endTime += stoi(frags[2].substr(0,2)) * 1000;
        endTime +=stoi(frags[2].substr(3, frags[2].size()-3));

        tokens[2] = tokens[2].substr(0, tokens[2].size()-1);
        bool dot = false;
        int dotAt = -1;
        for (int j = 0; j < tokens[2].size(); ++j) {
            if (tokens[2][j] == '.'){
                dot = true;
                dotAt = j;
                break;
            }
        }

        long long runtime = 0;
        if (!dot){
            runtime += stoi(tokens[2]) * 1000;
        }else{
            runtime += stoi(tokens[2].substr(0, dotAt)) * 1000;
            runtime += stoi(tokens[2].substr(dotAt+1, tokens[2].size()-dotAt-1));
        }


        long long startTime = endTime - runtime + 1;

        traffics.push_back(make_pair(startTime, endTime));
    }

    if (traffics.size() > 0) {

        for(int i=0 ;i<traffics.size(); i++) {
            int count = 1;
            for (int j = i+1; j < traffics.size() ; ++j) {
                if(traffics[j].first < traffics[i].second + 1000) count++;
            }
            if (answer < count) answer = count;
        }
    }

    return answer;
}
