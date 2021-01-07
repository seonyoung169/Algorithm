// #1 N개의 동전 -> 1010 구조 or 0101 구조로 만들기 위해서 뒤집어야 하는 동전 최소 갯수
// 네이버 지도 체험형 인턴 지원 문제

#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    if(A.size() == 1) return 0;

    int count = 0; //1-0-1-0 형식 기준으로 count
    int opposite;

    for(unsigned int i=0; i<A.size(); i++){
        if(i%2 == 0){ //짝수 index - 0,2,4,6,,,
            if(A[i] == 0){
                count++;
            }
        } else{ //홀수 index - 1,3,5,7,,,
            if(A[i] == 1){
                count++;
            }
        }
    }

    opposite = A.size() - count;
    return min(count, opposite);
}
int main(){

    vector<int> test = {0,1,0,1,0,1};

    cout<<solution(test)<<'\n';

    return 0;
}
