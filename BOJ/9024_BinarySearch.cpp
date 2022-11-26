#include <iostream>
#include <algorithm>
#define INT_MAX 2147483647

// boj 9024 두 수의 합, 이분 탐색

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;

    for (int i = 0; i < T; ++i) {
        int N, K;
        cin>>N>>K;

        int arr[1000000] = {0,};
        for (int j = 0; j < N; ++j) cin>>arr[j];
        sort(arr, arr+N);

        int count = 0;
        int minDiff = INT_MAX;
        int left = 0, right = N-1;

        while (left<right) {
            int sum = arr[left] + arr[right];
            int diff = abs(sum-K);

            if(sum>K) right--;
            else if (sum<K) left++;
            else {
                right--;
                left++;
            }

            if (minDiff>diff) {
                minDiff = diff;
                count = 1;
            }else if (minDiff==diff) count++;
        }

        cout<<count<<'\n';
    }

    return 0;
}
