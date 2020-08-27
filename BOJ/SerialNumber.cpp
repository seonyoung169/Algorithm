#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

//BOJ 1431 시리얼 반호 정렬 문제, 맞음 
using namespace std;

int getStringSum(string str){
    // 문자열 내에 있는 수들의 합 반환 함수
    int sum = 0;
    char cStr[50];
    strcpy(cStr, str.c_str());

    for(int i=0; i<strlen(cStr); i++){
        if(cStr[i]>= '0' && cStr[i] <= '9'){
            sum += cStr[i] - '0';
        }
    }

    return sum;
}

bool compare(string a, string b){
    if( a.length() < b.length()){
        return 1;
    } else if (a.length() > b.length()){
        return 0;
    }else{
        int aSum = getStringSum(a);
        int bSum = getStringSum(b);

        if(aSum != bSum){
            return aSum < bSum;
        }else{
            return a < b;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    string str;
    vector<string> serialNumbers;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>str;
        serialNumbers.push_back(str);
    }

    sort(serialNumbers.begin(), serialNumbers.end(), compare);

    cout<<serialNumbers.at(0)<<'\n';
    for(int i=1 ;i<N; i++){
        if(serialNumbers.at(i-1) != serialNumbers.at(i)){
            cout<<serialNumbers.at(i)<<'\n';
        }
    }

    return 0;
}
