#include <iostream>
#include <string>
#include <map>

// 프로그래머스 숫자 문자열과 영단어 kakao 2021 채용 연계형 
using namespace std;

string strNum[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    map<string, string> dictionary;
    for (int i = 0; i <= 9 ; ++i) {
        dictionary[strNum[i]] = to_string(i);
    }

    string changed = "";

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9'){
            changed += s[i];
        }else{
            string num = "";
            num += s[i];

            int j = i+1;
            while ( j<s.size() && dictionary.count(num) == 0){
                num += s[j++];
            }
            changed += dictionary[num];
            i = j-1;
        }
    }

    return stoi(changed);
}
