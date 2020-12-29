#include <iostream>
#include <stack>
#include <map>
#include <string>

// Codility Stack and Queues #1 Brackets, 100% 맞음

using namespace std;

int solution(string &S) {
    if (S.empty()) return 1;

    stack<char> stack;
    map<char, char> pairMap;
    pairMap['('] = ')';
    pairMap['{'] = '}';
    pairMap['['] = ']';

    for (int i = 0; i < S.size(); ++i) {
        char ch = S[i];

        if(ch == '(' || ch =='{' || ch == '[') stack.push(ch);
        else {
            if (stack.empty()) return 0;
            else {
                char left = stack.top();
                stack.pop();
                if (pairMap[left] != ch) return 0;
            }
        }
    }

    if(stack.empty()) return 1;
    else return 0;
}

int main() {
    string s = "([][])))";

    cout<<solution(s)<<'\n';

    return 0;
}
