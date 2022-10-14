#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// boj 7490 0만들기, 골드 5, 문자열
using namespace std;

vector<string> op = {"+", "-", " "};
vector<vector<string>> permutations;

void dfs(int N, int now, vector<string> arr) {
    if(arr.size() == 2*N-2) {
        arr.push_back(to_string(N));
        permutations.push_back(arr);
        return;
    }

    arr.push_back(to_string(now));
    for (int i = 0; i < 3; ++i) {
        vector<string> added = arr;
        added.push_back(op[i]);
        dfs(N, now+1, added);
    }
}

vector<string> makeEquation(vector<string> oper) {
    vector<string> result = {"1"};

    for (int i = 1; i < oper.size(); i+=2) {
        if(oper[i] == " ") {
            string last = result[result.size()-1];
            result[result.size()-1] = last+ oper[i+1];
        } else {
            result.push_back(oper[i]);
            result.push_back(oper[i+1]);
        }
    }

    return result;
}

int doMath(vector<string> equation) {
    int result = stoi(equation[0]);

    for (int i = 1; i <equation.size(); i+=2) {
        if(equation[i] == "+") {
            result += stoi(equation[i+1]);
        } else{
            result -= stoi(equation[i+1]);
        }
    }

    return result;
}

vector<vector<string>> solution(int N) {
    vector<vector<string>> answer;
    permutations.clear();

    dfs(N, 1, vector<string>());

    for (int i = 0; i < permutations.size(); ++i) {
        vector<string> equation = makeEquation(permutations[i]);
        int math = doMath(equation);
        if(math == 0) {
            answer.push_back(permutations[i]);
        }
    }

    return answer;
}


int main() {
    int T;
    cin>>T;

    for (int i = 0; i <T; ++i) {
        int N;
        cin >> N;
        vector<vector<string>> answer = solution(N);
        sort(answer.begin(), answer.end());
        for (int i=0; i<answer.size(); i++) {
            for (int j = 0; j < answer[i].size(); ++j) {
                cout<<answer[i][j];
            }
            cout<<'\n';
        }
        cout<<'\n';
    }

    return 0;
}
