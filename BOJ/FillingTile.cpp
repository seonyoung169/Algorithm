#include <iostream>

//BOJ 2133 타일링 문제 - dynamic programming
using namespace std;

int tile[31];

int dp(int n){
    if(n==0) return 1;
    if(n==1) return 0;
    if(n==2) return 3;
    if(tile[n] != 0) return tile[n];

    int result = 3 * dp(n-2);
    for(int i=3; i<=n; i++){
        if( i%2 ==0 ){
            result += 2*dp(n-i);
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin>>N;

    cout<<dp(N)<<'\n';

    return 0;
}
