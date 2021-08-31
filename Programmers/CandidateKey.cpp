#include <vector>
#include <map>
#include <algorithm>

// 프로그래머스 후보키, kakao 2019 blind, level2
using namespace std;

vector<vector<int>> getCombination(vector<int> keys, int r){
    vector<vector<int>> combinations;

    vector<bool> select( keys.size()-r, false);
    for (int i = 0; i < r; ++i) select.push_back(true);

    do{
        vector<int> combi;
        for (int i = 0; i < select.size(); ++i) {
            if (select[i]) combi.push_back(keys[i]);
        }
        combinations.push_back(combi);
    }while (next_permutation(select.begin(), select.end()));

    return combinations;
}


int solution(vector<vector<string>> relation) {
    int columnSize = relation[0].size(), rowSize = relation.size();
    map<vector<int>, bool> candidateKey;
    vector<int> notCandidate;


    for (int i = 0; i < columnSize; ++i) {
        map<string, bool> checkAttribute;
        bool able = true;
        for (int j = 0; j < rowSize; ++j) {
            string attribute = relation[j][i];
            if (checkAttribute.find(attribute) != checkAttribute.end()) {
                able = false;
                break;
            }else{
                checkAttribute[attribute] = true;
            }
        }
        if (able) candidateKey[{i}] = true;
        else notCandidate.push_back(i);
    }

    for (int r = 2; r <= notCandidate.size(); ++r) {
        vector<vector<int>> groupKeys = getCombination(notCandidate, r);

        for (int i = 0; i < groupKeys.size(); ++i) {
            map<string, bool> checkAttribute;
            bool able = true;

            // 유일성 검사
            for (int j = 0; j < rowSize; ++j) {
                string groupAttribute = "";
                for (int k = 0; k < groupKeys[i].size(); ++k) {
                    groupAttribute += relation[j][groupKeys[i][k]];
                }

                if (checkAttribute.find(groupAttribute) != checkAttribute.end()){
                    able = false;
                    break;
                }else{
                    checkAttribute[groupAttribute] = true;
                }
            }

            // 최소성 검사
            if (able){
                bool isMinimal = true;
                for (int j = 1; j < groupKeys[i].size(); ++j) {
                    vector<vector<int>> partKeys = getCombination(groupKeys[i], j);
                    for (int k = 0; k < partKeys.size(); ++k) {
                        if (candidateKey.find(partKeys[k]) != candidateKey.end()) {
                            isMinimal = false;
                            break;
                        }
                    }
                }
                if (isMinimal) candidateKey[groupKeys[i]] = true;
            }

        }
    }

    return candidateKey.size();
}
