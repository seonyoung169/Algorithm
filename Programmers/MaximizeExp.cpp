#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdlib.h>

// 프로그래머스 수식 최대화, level 2, 브루트포스, 2020 카카오 인턴십 
using namespace std;

vector<string> tokenize(string exp, vector<string> & operators){
    vector<string> tokens;

    int last = 0;
    for (int i = 1; i < exp.size(); ++i) {
        if (exp[i] == '*' || exp[i] == '+' || exp[i] == '-') {
            tokens.push_back(exp.substr(last, i-last));
            tokens.push_back(exp.substr(i,1));
            operators.push_back(exp.substr(i,1));
            last = i+1;
        }
    }
    tokens.push_back(exp.substr(last, exp.size()-last));
    return tokens;
}

vector<vector<string>> getPermutation(vector<string> list){
    vector<vector<string>> permutations;

    do{
        permutations.push_back(list);
    }while (next_permutation(list.begin(), list.end()));

    return permutations;
}

string calculate(string front, string back, string oper){
    long long  cal;
    if (oper == "+") cal = stoll(front) + stoll(back);
    if (oper == "-") cal = stoll(front) - stoll(back);
    if (oper == "*") cal = stoll(front) * stoll(back);
    return to_string(cal);
}

long long solution(string expression) {
    long long answer = 0;
    vector<string> opers;
    vector<string> tokens = tokenize(expression, opers);
    sort(opers.begin(), opers.end());

    vector<string> operList = opers;

    sort(operList.begin(), operList.end());
    operList.erase(unique(operList.begin(), operList.end()), operList.end());

    vector<vector<string>> permutaions = getPermutation(operList);

    for (int i = 0; i < permutaions.size(); ++i) {
        vector<string> copyToken = tokens;
        for (int j = 0; j < operList.size(); ++j) {
            string nowOper = permutaions[i][j];
            stack<string> calculated;

            for (int k = 0; k < copyToken.size(); ++k) {
                if (k%2 == 0) calculated.push(copyToken[k]);
                else{
                    if (copyToken[k] == nowOper){
                        string front = calculated.top();
                        calculated.pop();
                        string back = copyToken[k+1];
                        string sub = calculate(front, back, copyToken[k++]);
                        calculated.push(sub);
                    }else{
                        calculated.push(copyToken[k]);
                    }
                }
            }

            copyToken.clear();
            copyToken.assign(calculated.size(), "");
            int index = copyToken.size()-1;

            while (!calculated.empty()){
                copyToken[index--] = calculated.top();
                calculated.pop();
            }

        }

        long long result = stoll(copyToken[0]);
        result = abs(result);

        if (answer < result) answer = result;
    }


    return answer;
}
