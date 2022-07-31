#include <iostream>
#include <vector>
#include <algorithm>

// boj 2877 4와 7, 실버 1, 구현
using namespace std;

void solve(int K) {
    int sum = 2, n = 1, j = 2;

    while (sum<K) {
        sum += j*2;
        j *= 2;
        n++;
    }

    int left = K-(sum-j)-1;
    vector<int> temp(n+1);

    for (int i = n-1; i>=0; i--) {
        if (left==0 || left%2 == 0) temp[i] = 4;
        else temp[i] = 7;
        left = left/2;
    }

    string answer = "";
    for (int i = 0; i < n; ++i) {
        cout<<temp[i];
    }
}

int main() {

    int K;
    cin>>K;

    solve(K);

    return 0;
}
