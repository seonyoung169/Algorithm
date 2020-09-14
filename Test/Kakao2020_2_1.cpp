#include <string>
#include <vector>
#include <algorithm>

//카카오 2020하반기 블라인드 1번
using namespace std;

bool isRightChar(char ch){
    if( ch>=97 && ch<=122) return true;
    if( ch>=48 && ch<= 57) return true;
    if( ch == '-' || ch == '_' || ch == '.') return true;
    return false;
}
string solution(string new_id) {
    string answer = "";
    answer = new_id;

    //1. 소문자로 변환
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

    //2. 소문자, 숫자, 빼기, 밑줄, 마침표 제외 모든 문자 제거
    for(int i=0; i<answer.size(); i++) {
        if(!isRightChar(answer[i])){
            answer.erase(i,1);
            i--;
        }
    }

    //3. 마침표가 2개 이상이면 하나로 치환
    for(int i=1; i<answer.size(); i++){
        if(answer[i] == '.' && answer[i-1] == '.'){
            answer.erase(i,1);
            i--;
        }
    }

    //4. 처음과 끝에 마침표가 존재하면 제거
    if(answer[0] == '.') answer.erase(0,1);
    int end = answer.size()-1;
    if(answer[end] == '.') answer.erase(end,1);

    //5. 빈 문자열이면 "a" 대입
    if(answer.empty()) answer = "a";

    //6. 길이가 16 이상이면 15까지 줄이기, 마지막이 마침표이면 제거
    if(answer.size() > 15){
        answer = answer.substr(0,15);
        if(answer[14] == '.') answer.erase(14,1);
    }


    //7. 길이가 2자 이하라면 마지막 문자를 3이상될때까지 반복
    if(answer.size() <3){
        while (answer.size() < 3){
            end = answer.size()-1;
            answer += answer[end];
        }
    }

    return answer;
}

int main(){
    string answer = solution("abcdefghijklmn.p");

    return 0;
}
