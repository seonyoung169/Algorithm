#include <iostream>
#include <vector>
#include <algorithm>

// boj 1477 휴게소 세우기, 골드 4, 이분 탐색
using namespace std;

int binary_search(vector<int> store_position, int M, int L){
    int left = 1, right = L-1;

    while (left<=right){
        int mid = (left+right)/2;
        int count = 0;
        for (int i = 1; i < store_position.size(); ++i) {
            int section = store_position[i]-store_position[i-1];

            count += section/mid;
            if(section%mid == 0) count--;
        }

        if(count>M) left = mid+1;
        else right = mid-1;
    }

    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, L;
    cin>>N>>M>>L;

    vector<int> store_position(N+2);

    store_position[0] = 0;
    for (int i = 1; i <= N; ++i) cin>>store_position[i];
    store_position[N+1] = L;

    sort(store_position.begin(), store_position.end());

    cout<<binary_search(store_position, M, L);

    return 0;
}
