#include <string>
#include <vector>
#include <algorithm>

// 2021 KAKAO BLIND RECRUITMENT 메뉴 리뉴얼

using namespace std;

bool byLength(string a, string b){
    if (a.size() != b.size()){
        return a.size() < b.size();
    }
    return a<b;
}

bool byPairLength(pair<string, int> a, pair<string, int> b){
    if (a.first.size() != b.first.size()){
        return a.first.size() < b.first.size();
    }
    return a.first<b.first;
}

bool byLenghtAndCount(pair<string, int> a, pair<string, int> b) {
    if (a.first.size() == b.first.size()){
        return a.second > b.second;
    }else{
        return a.first.size() < b.first.size();
    }
}

void getCombination(vector<char> alphaets, int r, vector<pair<string, int>> & combinations){
    int n = alphaets.size();

    vector<bool> select(n-r, false);
    for (int i = 0; i < r; ++i) {
        select.push_back(true);
    }

    do{
        string combi = "";
        for (int i = 0; i < n; ++i) {
            if (select[i]){
                combi += alphaets[i];
            }
        }
        combinations.push_back(make_pair(combi, 0));
    }while (next_permutation(select.begin(), select.end()));
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    sort(orders.begin(), orders.end(), byLength);


    vector<pair<string, int>> combinations;
    vector<vector<bool>> orderCheck(orders.size(), vector<bool>(27, false));

    for (int i = 0; i < orders.size(); ++i) {
        vector<char> alphabets;
        for (int j = 0; j < orders[i].size(); ++j) {
            alphabets.push_back(orders[i][j]);
            orderCheck[i][orders[i][j]-64] = true;
        }
        sort(alphabets.begin(), alphabets.end());

        for (int j = 0; j < course.size(); ++j) {
            if (course[j] <= orders[i].size()){
                getCombination(alphabets, course[j], combinations);
            }
            else break;
        }
    }

    sort(combinations.begin(), combinations.end(), byPairLength);
    combinations.erase(unique(combinations.begin(), combinations.end()), combinations.end());

    int maxLen = course[course.size()-1];
    vector<int> maxCount(maxLen+1, -1);

    for (int i = 0; i < combinations.size(); ++i) {
        int count = 0;
        int courseLen = combinations[i].first.size();

        for (int j = 0; j < orders.size(); ++j) {
            if(courseLen <=  orders[j].size()){
                bool same = true;
                for (int k = 0; k < courseLen; ++k) {
                    if (!orderCheck[j][combinations[i].first[k]-64]){
                        same = false;
                        break;
                    }
                }
                if (same) count++;
            }
        }
        combinations[i].second = count;
        if(count >= 2 && count > maxCount[courseLen]) maxCount[courseLen] = count;
    }

    sort(combinations.begin(), combinations.end(), byLenghtAndCount);


    for (int i = 0; i < combinations.size(); ++i) {
        int len = combinations[i].first.size();
        if (combinations[i].second == maxCount[len]){
            answer.push_back(combinations[i].first);
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}
