#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

// 프로그래머스 외벽 점검, level 3, bruteforce, 순열 이용
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = INT_MAX, P = weak.size();

    for (int i = 0; i < P; ++i) weak.push_back(weak[i]+n);
    sort(dist.begin(), dist.end());

    do {
        for (int i = 0; i<P; i++){
            int from = i, to = i+P-1;
            for (int j = 0; j < dist.size(); ++j) {
                int max = weak[from] + dist[j];
                if(max >= weak[to]){
                    answer = min(answer, j+1);
                    break;
                }

                while (weak[from] <= max){
                    from++;
                }
            }
        }

    }while (next_permutation(dist.begin(),dist.end()));

    if (answer==INT_MAX) answer = -1;

    return answer;
}
int main() {
    int answer;
    answer = solution(12, {1, 5, 6, 10}, {1,2,3,4});

    cout<<answer;
    return 0;
}
