//프로그래머스 정렬 #2 가장 큰 수, 성공

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b){
    return (a+b) > (b+a);
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strnumbers;

    for(int i=0; i<numbers.size(); i++){
        strnumbers.push_back(to_string(numbers[i]));
    }

    sort(strnumbers.begin(), strnumbers.end(), compare);

    if(strnumbers[0] == "0") return "0";

    for(int i=0; i<strnumbers.size(); i++){
        answer += strnumbers[i];
    }

    return answer;
}
int main(){

    string ans = solution({6,10, 2});

    cout<<ans<<'\n';
    return 0;
}
