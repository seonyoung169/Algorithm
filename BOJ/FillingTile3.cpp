//ios_base::sync_with_stdio(false);
//cin.tie(nullptr);
//cout.tie(nullptr);

#include <iostream>

//BOJ 14852 타일 채우기 3 - 2차원 dynamic programming 이용하기, 맞
using namespace std;

long long int d[1000001][2];

long long int tiling(int n){
    d[0][0] = 0;
    d[1][0] = 2;
    d[2][0] = 7;음
    d[2][1] = 1;

    for(int i=3; i<=n; i++){
        d[i][1] = (d[i-3][0] + d[i-1][1]) % 1000000007;
        d[i][0] = (2*d[i-1][0] + 3*d[i-2][0] + 2*d[i][1]) % 1000000007;
    }

    return d[n][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin>>N;

    cout<<tiling(N)<<'\n';

    return 0;
}
