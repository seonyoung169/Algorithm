#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

// 프로그래머스 순위 검색, level 3, 2021 kakao blind
using namespace std;

// 4개의 조건 중 r개를 요구하지 않는 경우 구하기 
vector<string> getCombinations(vector<string> tokens, int r) {
    vector<string> combinations;
    vector<bool> select(4 - r, false);
    for (int i = 0; i < r; ++i) select.push_back(true);

    do {
        string key = "";
        for (int i = 0; i < 4; ++i) {
            if (select[i]) key += "-";
            else key += tokens[i];

            if (i < 3) key += " ";
        }
        combinations.push_back(key);

    } while (next_permutation(select.begin(), select.end()));

    return combinations;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string, vector<int>> applyMap;  // 요구 조건이 key 가 되고 해당하는 지원자의 점수를 담아둠 

    for (int i = 0; i < info.size(); ++i) {
        istringstream ss(info[i]);
        vector<string> tokens;  
        string tok;

        // 지원자의 정보 파씽해서 맵에 저장 
        while (getline(ss, tok, ' ')){
            tokens.push_back(tok);
        }

        int score = stoi(tokens[4]);
        for (int r = 0; r <= 4 ; ++r) {
            vector<string> keys = getCombinations(tokens, r);

            for (int j = 0; j < keys.size(); ++j) {
                applyMap[keys[j]].push_back(score);
            }
        }
    }

    // map 의 각 점수들 오름차순 정렬
    for (auto iter = applyMap.begin() ; iter != applyMap.end(); iter++) {
        sort(iter->second.begin(), iter->second.end());
    }

    // query 탐색
    for (int i = 0; i < query.size(); ++i) {
        istringstream ss(query[i]);
        vector<string> tokens;
        string buffer;

        // query 를 파싱해 map 의 key로 변환 
        while (getline(ss, buffer, ' ')){
            tokens.push_back(buffer);
        }

        int cut = stoi(tokens[7]);
        string condition = "";
        for (int j = 0; j < 7; ++j) {
            if (j % 2 == 0) {
                condition += tokens[j];
                if (j<5) condition += " ";
            }
        }

        // applyMap 에 condition 키로 점수 배열 중에서 cut 이상인 사람 count
        vector<int> scores = applyMap[condition];
        vector<int>::iterator low = lower_bound(scores.begin(), scores.end(), cut);

        answer.push_back(scores.size()-1 - (low-scores.begin()) +1);

    }

    return answer;
}
