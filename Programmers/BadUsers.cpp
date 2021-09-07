
#include <string>
#include <vector>
#include <algorithm>

// 프로그래머스 불량 사용자, level 3, brute force, 2019 카카오 겨울 인턴십
using namespace std;

bool isPossible(string origin, string ban){
    for (int i = 0; i < origin.length(); ++i) {
        if (ban[i] == '*') continue;
        if (origin[i] != ban[i]) return false;
    }
    return true;
}

bool isMapped(vector<string> id, vector<string> banned){
    sort(id.begin(), id.end());
    do{
        bool match = true;
        for (int i = 0; i < id.size(); ++i) {
            if (id[i].length() != banned[i].length() || !isPossible(id[i], banned[i])){
                match = false;
                break;
            }
        }
        if (match) return true;
    }while (next_permutation(id.begin(), id.end()));

    return false;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int n = user_id.size(), r = banned_id.size();

    vector<bool> select(n-r, false);
    for (int i = 0; i < r; ++i)  select.push_back(true);

    vector<vector<string>> combinations;

    do{
        vector<string> picked;
        for (int i = 0; i < n; ++i) {
            if (select[i]) picked.push_back(user_id[i]);
        }
        combinations.push_back(picked);
    }while (next_permutation(select.begin(), select.end()));


    for (int i = 0; i < combinations.size(); ++i) {
        if(isMapped(combinations[i], banned_id)) answer++;
    }

    return answer;
}
