#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// BOJ 1759 암호 만들기, 브루트포스 & 조합 이용
// break 대신 continue 사용해야함..!

using namespace std;

vector<string> getCombination(vector<string> characters, int r) {
    int len = characters.size();

    vector<string> answer;

    vector<bool> check(len - r, false);
    check.insert(check.end(), r, true);

    do {
        string temp = "";
        for (int j = 0; j < len; j++) {
            if (check[j]) {
                temp += characters[j];
            }
        }
        answer.push_back(temp);
    } while (next_permutation(check.begin(), check.end()));

    return answer;
}

int main() {
    int L, C;
    cin>>L>>C;

    vector<string> answer;
    vector<string> vowel;
    vector<string> consonant;

    string ch;
    for (int i = 0; i < C ; ++i) {
        cin>>ch;
        if(ch=="a" || ch=="e" || ch=="i" || ch=="u" || ch=="o"){
            vowel.push_back(ch);
        }else{
            consonant.push_back(ch);
        }
    }

    vector<string> usedV;
    vector<string> usedC;

    for (int v = 1; v <=vowel.size() ; ++v) {
        int c = L-v;

        if (c>=2 && c<=consonant.size()){
            usedV = getCombination(vowel, v);
            usedC = getCombination(consonant, c);
        }else continue;

        for (int i = 0; i < usedV.size() ; ++i) {
            for (int j = 0; j < usedC.size(); ++j) {
                string ans = usedV[i]+usedC[j];

                sort(ans.begin(), ans.end());
                answer.push_back(ans);
            }
        }
    }

    sort(answer.begin(), answer.end());

    for (int i = 0; i < answer.size(); ++i) {
        if (i < answer.size()-1){
            cout<<answer[i]<<'\n';
        }else{
            cout<<answer[i];
        }
    }

    return 0;
}
