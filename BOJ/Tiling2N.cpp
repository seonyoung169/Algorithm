#include <iostream>

//BOJ 11726 타일링 문제 - dynamic programming
using namespace std;

int tile[1001];

int dp(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(tile[n] != 0) return tile[n];

    return ( tile[n] = (dp(n-1) + dp(n-2)) % 10007 );
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
