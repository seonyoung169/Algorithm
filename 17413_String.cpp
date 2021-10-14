#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

// boj 17413 단어 뒤집기2, 실버 3, 문자열
using namespace std;

string tokenize(string temp){
    string result = "";
    istringstream ss(temp);
    vector<string> tokens;
    string tk;

    while (getline(ss, tk, ' ')){
        tokens.push_back(tk);
    }

    for (int i = tokens.size()-1; i >=0 ; --i) {
        if (i<tokens.size()-1) result += " ";
        result += tokens[i];
    }

    return result;
}

string convertStr(string str){
    string result = "";
    int i = 0;

    stack<string> st;

    while (i<str.size()){
        if (str[i] == ' '){
            result += " ";
            i++;
            continue;
        }

        if (str[i] == '<'){
            while (str[i] !='>'){
                result += str.substr(i++, 1);
            }
            result += str.substr(i++, 1);
        }else{
            while (i<str.size() && str[i] != '<'){
                st.push(str.substr(i++, 1));
            }


            string temp = "";
            while (!st.empty()){
                temp += st.top();
                st.pop();
            }

            result += tokenize(temp);
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    getline(cin, str);

    string answer = convertStr(str);
    cout<<answer;

    return 0;
}
