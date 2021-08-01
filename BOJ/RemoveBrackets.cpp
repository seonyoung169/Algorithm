#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

// BOJ 2800 괄호 제거 
using namespace std;

// 제거할 괄호 조합 구하기
vector<vector<pair<int, int>>> makeCombinations(vector<pair<int, int>> array) {
    vector<vector<pair<int, int>>> results;
    int length = array.size();

    for (int i = 1; i <= length ; ++i) {

        vector<bool> choose(length-i, false);
        for (int j = 0; j < i; ++j) {
            choose.push_back(true);
        }

        do {
            vector<pair<int, int>> comb;
            for (int k = 0; k < length; ++k) {
                if (choose[k]) comb.push_back(array[k]);
            }
            results.push_back(comb);
        }while (next_permutation(choose.begin(), choose.end()));
    }

    return results;
}

// 조합별로 괄호 제거한 string 구하기
vector<string> removeBracket(string input) {
    vector<string> answer;
    stack<pair<char, int>> st;
    vector<pair<int, int>> brackets;

    for (int i = 0; i < input.size(); ++i) {
        char ch = input[i];

        if(ch != ')'){
            st.push(make_pair(ch, i));
        }else{  // 우괄호를 찾으면
            while (!st.empty()){
                pair<char, int> pop = st.top();
                st.pop();

                // 좌괄호를 찾아서 두 쌍의 위치를 저장
                if (pop.first == '('){
                    brackets.push_back(make_pair(pop.second, i));
                    break;
                }else continue;
            }
        }
    }

    // 알아낸 괄호 쌍별 위치를 기준으로 가능한 조합 구하기
    vector<vector<pair<int, int>>> combinations = makeCombinations(brackets);

    for (int i = 0; i < combinations.size(); ++i) {
        vector<bool> print(input.size(), true);

        // 조합별로 출력 가능 위치 파악 
        for (int j = 0; j < combinations[i].size(); ++j) {
            print[combinations[i][j].first] = false;
            print[combinations[i][j].second] = false;
        }

        // 조합별 출력 string 저장 
        string ans = "";
        for (int k = 0; k < input.size(); ++k) {
            if (print[k]) ans += input[k];
        }

        answer.push_back(ans);
    }

    return answer;

}

int main() {
    string input;
    cin>>input;

    vector<string> answer = removeBracket(input);

    // 중복되는 것 없게, 사전순으로 정렬해서 출력 
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(),answer.end()),answer.end());

    for (int i = 0; i < answer.size() ; ++i) {
        cout<<answer[i]<<'\n';
    }

    return 0;

}
