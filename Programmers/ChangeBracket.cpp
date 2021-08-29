#include <string>
#include <stack>

// 프로그래머스 괄호 변환 2020 카카오 블라인드
using namespace std;

string convert(string u) {
    string converted = u.substr(1, u.size()-2);

    for (int i = 0; i < converted.size(); ++i) {
        if (converted[i] == '(') converted[i] = ')';
        else converted[i] = '(';
    }
    return converted;
}

// u가 올바른 문자열인지 확인
bool isCorrect(string u){
    stack<char> brackets;
    brackets.push(u[0]);

    for (int i = 1; i < u.size(); ++i) {
        if (u[i] == ')'){
            if (brackets.empty()) return false;
            if (brackets.top() != '(') return false;
            brackets.pop();
        }else{
            brackets.push(u[i]);
        }
    }

    if (!brackets.empty()) return false;
    return true;
}

string solution(string p) {
    if (p == "") return "";

    string u = "", v = "", answer = "";
    int head = 0, tail = 0;

    // u, v 확인
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] == '(') head++;
        else tail++;

        if (head == tail){
            u = p.substr(0, i+1);
            v = p.substr(i+1, p.size()-i-1);
            break;
        }
    }

    if (isCorrect(u)){
        answer = u + solution(v);
    }else{
        answer = "(" + solution(v) + ")" + convert(u);
    }

    return answer;
}
