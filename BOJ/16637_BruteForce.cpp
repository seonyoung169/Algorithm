#include <iostream>
#include <string>
#include <vector>

// BOJ 16637 괄호 추가하기, 브루트포스 ,골드 3
using namespace std;

int N;
string formula;
int MAXIMUM = -2147483648;

char getOpposite(char method){
    switch (method) {
        case '+':
            return '-';
        case '-':
            return '+';
        case '*':
            return '/';
        case '/':
            return '*';
    }
}

int calculate(int a, int b, char method){
    switch (method) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }
}
void addBracket(int result, int curr, bool bracket, vector<int> memo) {
    if (curr > N-1){  // 종료조건
        if (result > MAXIMUM) MAXIMUM = result;
        return;
    }

    int newResult = calculate(result, formula[curr+1]-'0', formula[curr]);
    memo[curr+1] = newResult;
    addBracket(newResult, curr+2, false, memo);

    if (!bracket){  // 이전에 괄호 없었다면 괄호 연산 추가 적용
        int lastNumber = formula[curr-1]-'0';
        char lastMethod = formula[curr-2];
        char opposite = getOpposite(lastMethod);

        int lastResult;
        if (opposite == '/' && lastNumber ==0){
            lastResult = memo[curr-3];
        }else{
            lastResult = calculate(result, lastNumber, opposite);
        }
        int bracketed = calculate(lastNumber, formula[curr+1]-'0', formula[curr]);

        lastResult = calculate(lastResult, bracketed, lastMethod);
        addBracket(lastResult, curr+2, true, memo);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>formula;

    vector<int> memo(N, 0);

    if (N==1){
        MAXIMUM = formula[0]-'0';
    }else{
        int start = calculate(formula[0]-'0', formula[2]-'0', formula[1]);
        memo[0] = formula[0]-'0';
        memo[2] = start;

        addBracket(start, 3, false, memo);
        addBracket(start, 3, true, memo);
    }
    cout<<MAXIMUM;

    return 0;
}
