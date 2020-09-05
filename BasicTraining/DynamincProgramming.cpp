#include <iostream>

// Dynamic Programming 기초
using namespace std;

int d[101];

int fibonacci(int n){
    if(d[n] != 0) return d[n];
    return d[n] = fibonacci(n-1) + fibonacci(n-2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin>>N;

    d[1] = 1;
    d[2] = 1;

    cout<<fibonacci(N)<<'\n';

    return 0;
}

