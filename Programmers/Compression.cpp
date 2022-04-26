#include <string>
#include <vector>
#include <map>

// 프로그래머스 압축 leve2, 문자열 
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<string , int> dictionary;

    for (int i = 0; i < alphabet.size() ; ++i) {
        dictionary.insert({alphabet.substr(i,1), alphabet[i]-64});
    }

    int i = 0, len = msg.size(), dic_size = 26;
    while (i<len){
        int count = 1;
        while (i+count-1 < len && dictionary.find(msg.substr(i, count)) != dictionary.end()){
            count++;
        }

        answer.push_back(dictionary[msg.substr(i, count-1)]);
        if (i+count-1 >= len) break;

        dictionary.insert({msg.substr(i, count), ++dic_size});
        i += count-1;
    }

    return answer;
}

int main() {
    vector<int> ans;
    ans = solution("TOBEORNOTTOBEORTOBEORNOT");

    return 0;
}
