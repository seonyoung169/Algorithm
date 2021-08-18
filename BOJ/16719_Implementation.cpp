#include <iostream>
#include <vector>
#include <string>
#include <stack>

// BOJ 16719 ZOAC, 구현 골드 5
using namespace std;

void printByRule(string str){
    vector<string> answer;

    int len = str.size();
    vector<bool> printable(len, false);
    stack<int> flags;

    int start = 0;  // 출력 시작 점 찾기
    for (int i = 1; i < len; ++i) {
        if (str[start] > str[i]) start = i;
    }
    printable[start] = true;
    flags.push(start);

    int checked = 1;
    bool found = true;
    while (checked<=len){
        if (found){
            string ans = "";
            for (int i = 0; i < len; ++i) {
                if (printable[i]) ans += str[i];
            }
            answer.push_back(ans);
        }

        found = false;

        int next = 0;
        char min = '[';
        if (!flags.empty()){
            int last = flags.top();
            bool left = false;
            for (int i = last+1; i < len; ++i) {
                if (!printable[i] && (str[i] < min)){
                    left = true;
                    min = str[i];
                    next = i;
                }
            }

            if (left){  // last 이후로 출력할 게 남아있다면
                flags.push(next);
                printable[next] = true;
                checked++;
                found = true;
            }else{  // last 이후로 출력할게 없다면
                flags.pop();
            }
        }else{ // str 앞에서부터 출력할 문자 찾기
            for (int i = 0; i < len; ++i) {
                if (!printable[i] && (str[i] < min)){
                    min = str[i];
                    next = i;
                }
            }
            flags.push(next);
            printable[next] = true;
            checked++;
            found = true;
        }
    }

    for (int i = 0; i < answer.size(); ++i) {
        cout<<answer[i]<<'\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin>>str;

    printByRule(str);

    return 0;
}
