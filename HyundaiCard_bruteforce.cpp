#include <iostream>
#include <vector>
#include <string>

//현대카드 코딩테스트 - 시험 ip, 점수, 언어로 부정행위 학생 걸러내기

using namespace std;

int solution(vector<string> ip_addrs, vector<string> langs, vector<int> scores);
int sameLanguage(string lang1, string lang2);


int main(){
    vector<string> ip_addrs =  { "5.5.5.5", "155.123.124.111", "10.16.125.0", "155.123.124.111", "5.5.5.5", "155.123.124.111", "10.16.125.0", "10.16.125.0"};
    vector<string> langs = { "Java", "C++", "Python3", "C#", "Java", "C", "Python3", "JavaScript"};
    vector<int> scores = {294, 197, 373, 45, 294, 62, 373, 373};

    cout<<solution(ip_addrs,langs, scores);

}
int solution(vector<string> ip_addrs, vector<string> langs, vector<int> scores) {
    int answer = -1;
    answer = ip_addrs.size();
    int ipCnt, lanCheck = 0, scoreCheck = 0;

    vector<int> studentIdx;

    //부정행위 학생들 체크 배열 : 0 미검사, 1 정상 2 부정
    vector<int> studentCheck;
    for(int i=0;i<ip_addrs.size();i++) studentCheck.push_back(0);

    //학생들 대상으로 ip 주소 검사
    for(int i=0 ;i<ip_addrs.size() ;i++){
        //부정행위로 제외 되지 않은 학생들 대상으로 검사
        if(studentCheck[i] == 0){
            studentIdx.clear();
            ipCnt = 0;
            for(int j=i+1;j<ip_addrs.size();j++){
                if( ip_addrs[j] == ip_addrs[i]){
                    studentIdx.push_back(j);
                    ipCnt++;
                }
            }
            //같은 ip 주소가 4,3,2

            switch (ipCnt){
                case 1: //동일 ip 주소 2개 일 때
                    if(sameLanguage(langs[i], langs[studentIdx[0]])) {
                        if(scores[i] == scores[studentIdx[0]]){ // lang, score 모두 동일하면 부
                            studentCheck[i] = 2;
                            studentCheck[studentIdx[0]] = 2;
                            answer -= 2;
                        } else{ // 검사 완료
                            studentCheck[i] = 1;
                            studentCheck[studentIdx[0]] = 1;
                        }
                    }else{ //검사 완료
                        studentCheck[i] = 1;
                        studentCheck[studentIdx[0]] = 1;
                    }
                    break;
                case 2: //동일 ip 주소가 3개일 때
                    if(sameLanguage(langs[i], langs[studentIdx[0]]) && sameLanguage(langs[i], langs[studentIdx[1]])){ //3명 언어 동일 하면 부정
                        studentCheck[i] = 2;
                        studentCheck[studentIdx[0]] = 2;
                        studentCheck[studentIdx[1]] = 2;
                        answer -= 3;
                    } else{
                        studentCheck[i] = 1;
                        studentCheck[studentIdx[0]] = 1;
                        studentCheck[studentIdx[1]] = 1;
                    }
                    break;
                case 3: // 동일 ip 주소 4개
                    studentCheck[i] = 2;
                    studentCheck[studentIdx[0]] = 2;
                    studentCheck[studentIdx[1]] = 2;
                    studentCheck[studentIdx[2]] = 2;
                    answer -= 4;
                    break;
                default:
                    studentCheck[i] = 1;
                    break;
            }

        }
    }

    return answer;
}

int sameLanguage(string lang1, string lang2){
    if(!lang1.compare("Java") || !lang1.compare("JavaScript") || !lang1.compare("Python3")) {
        if (!lang1.compare(lang2)) return 1;
        else return 0;
    }else{
        if(lang2[0] == 'C') return 1;
        else return 0;
    }
}
