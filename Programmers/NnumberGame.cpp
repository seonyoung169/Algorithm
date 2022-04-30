#include <iostream>
#include <string>

// 프로그래머스 N진수 게임, level 2
using namespace std;

string ch[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

string n_converted(int num, int n){
    string result = "";

    while (num >= n){
        int left = num%n;
        result = ch[left] + result;
        num = num/n;
    }
    result = ch[num] + result;

    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string changed = "0";

    if (n==10){
        for (int i = 1; i < t*m; ++i) {
            changed += to_string(i);
        }
    }else{
        for (int i = 1; i < t*m; ++i) {
            changed += n_converted(i, n);
        }
    }


    int i = p-1;
    while (t > 0){
        answer += changed[i];
        i += m;
        t--;
    }

    return answer;
}
