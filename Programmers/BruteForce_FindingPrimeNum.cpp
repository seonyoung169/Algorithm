//프로그래머스 완전탐색 소수찾기, 맞음
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b){ return a > b; }

void primeNumberSieve(vector<bool> & primeNumCheck, int maxNum){
    for(int i=2; i<= maxNum; i++){
        if(!primeNumCheck[i]) continue;
        else{
            for(int j=i+i; j<=maxNum; j+=i){
                primeNumCheck[j] = false;
            }
        }
    }
}
int solution(string numbers) {
    int answer = 0;
    vector<char> numTokens;
    vector<char> copy;
    for(int i=0; i<numbers.length(); i++){
        numTokens.push_back(numbers[i]);
    }
    copy = numTokens;

    sort(numbers.begin(), numbers.end(), desc);
    int maxNum = atoi(numbers.c_str());

    vector<bool> primeNumCheck(maxNum+1, true);
    primeNumberSieve(primeNumCheck, maxNum);  //에라토스테네스의 체

    for(int i=2; i<primeNumCheck.size(); i++){
        if(primeNumCheck[i]){ //소수가 주어진 수로 만들어진 수인지 확인
            numTokens.clear();
            numTokens = copy;
            bool elementcheck = true;
            int num = i;
            while(num>0){
                int left = num%10;
                char ch = left + 48;
                bool flag = false;
                for(int j=0; j<numTokens.size(); j++){
                    if(numTokens[j] == ch){
                        numTokens.erase(numTokens.begin() + j);
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    elementcheck = false;
                    break;
                }
                num = num/10;
            }
            if(!elementcheck)  continue;
            else answer++;
        }
    }

    return answer;
}

int main(){

    int answer = solution("17");

    cout<<answer<<'\n';

    return 0;
}
