#include <iostream>
#include <string>
#include <vector>

// 프로그래머스 문자열 압축 2020 Kakao Blind Recruitment
using namespace std;

int solution(string s) {
    vector<string> check;
    int answer = s.size();

    for (int j = 1; j <= s.size()-1 ; ++j) {
        vector<string> units;
        string compressed = "";

        int i = 0;
        while (i+j < s.size()){
            units.push_back(s.substr(i, j));
            i += j;
        }
        if(i<s.size()) units.push_back(s.substr(i, s.size()-i));

        int count = 1;
        for (int k = 1; k < units.size(); ++k) {
            if (units[k] == units[k-1]) {
                count++;
                if (k == units.size()-1) {
                    compressed += to_string(count);
                }
            }
            else{
                if (count>1) compressed += to_string(count);
                compressed += units[k-1];
                count = 1;
            }
        }
        compressed += units[units.size()-1];

        check.push_back(compressed);
        if (compressed.size() < answer) answer = compressed.size();
    }

    return answer;
}

int main() {
    int answer;

    answer = solution("xababcdcdababcdcd");

    cout<<answer;

    return 0;

}
