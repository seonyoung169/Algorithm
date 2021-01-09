// #2 정수 N -> 각 자리 수를 합해서 N이 되는 최소 수 구하기
// 네이버 지도 체험형 인턴 

#include <iostream>
#include <string>

using namespace std;

int solution(int N) {
    //한자리 수 일 때 (0~9)
    if(N/10 == 0) return N;

    string answer = "";
    //두자리수 (10~50)
    while (N >= 10){
        answer.insert(0, "9");
        N -= 9;
    }
    answer.insert(0,to_string(N));

    return stoi(answer);
}

int main(){

    cout<<solution(19)<<'\n';

    return 0;
}
