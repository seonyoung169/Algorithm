#include <iostream>
#include <vector>
#include <algorithm>

// BOJ 2110 공유기 설치, Binary Search, 실버 1 
using namespace std;

int findGap(vector<int> house, int N, int C){
    int answer;
    int minGap = 1, maxGap = house[house.size()-1] - house[0];
    int mid;

    while (minGap <= maxGap){
        mid = (minGap + maxGap)/2;
        int router = 1;
        int last = 0, next = 1;

        while (next<N && router<C){
            if (house[next]>= house[last]+mid){
                router++;
                last = next;
                next = last+1;
            }else{
                next++;
            }
        }

        if (router < C){
            maxGap = mid-1;
        }else if (router == C){
            answer = mid;
            minGap = mid+1;
        }else{
            minGap = mid+1;
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C;
    cin>>N>>C;

    vector<int> house(N, 0);
    for (int i = 0; i < N; ++i) {
        cin>>house[i];
    }

    sort(house.begin(), house.end());

    int answer = findGap(house, N, C);

    cout<<answer;

    return 0;
}
