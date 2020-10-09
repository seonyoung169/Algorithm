#include <iostream>

//BOJ 1463 1로 만들기 - bottom up DP 사용, 맞음!
using namespace std;

int dp[1000001];

int main(){
    int X;
    cin>>X;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    if(X > 3){
        for(int i=4; i<=X; i++){
            int min = dp[i-1] + 1;
            int temp;
            if(i%2 == 0){
                temp = dp[i/2] + 1;
                if(min > temp){
                    min = temp;
                }
            }
            if(i%3 == 0){
                temp = dp[i/3] + 1;
                if(min > temp){
                    min = temp;
                }
            }
            dp[i] = min;
        }
    }

    cout<<dp[X]<<'\n';

    return 0;
}
