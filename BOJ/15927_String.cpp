#include <iostream>
#include <vector>
#include <string>

// boj 15927 회문은 회문이 아니야, 문자열, 골드 5
using namespace std;

int chracterCnt = 0;

bool check(string str) {
    vector<bool> alphabet(26, false);

    int left = 0, right = str.size()-1;

    while (left<=right) {
        if(str[left]!=str[right]) return false;

        if (!alphabet[str[left]-65]) {
            alphabet[str[left]-65] = true;
            chracterCnt++;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    string str;
    cin>>str;

    if(!check(str)) cout<<str.size();
    else{
        if(chracterCnt == 1) cout<<-1;
        else cout<<str.size()-1;
    }

    return 0;
}
