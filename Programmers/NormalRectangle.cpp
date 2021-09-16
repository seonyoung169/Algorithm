#include <cmath>

// 프로그래머스 멀쩡한 사각형, level 2, 수학 문제, 자료형 조심!
using namespace std;

int getGCD(long long a, long long b){
    int small, big;
    if(a>b) { 
        big = a; 
        small = b;
    } else{
        big = b;
        small = a;
    }
    
    int mod = big%small;
    
    while(mod>0){
        big = small;
        small = mod;
        mod = big%small;
    }
    
    return small;
}

long long solution(int w,int h) {
    long long W = w;
    long long H = h;
    
    int gcd = getGCD(W, H);
    
    long long total = W*H;
    long long answer = total - (W+H-gcd);
    
    return answer;
}
