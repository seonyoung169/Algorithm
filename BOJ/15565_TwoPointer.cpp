#include <iostream>
#include <vector>

// BOJ 15565 귀여운 라이언, 실버 1, 투포인터
using namespace std;

int getMinSize(vector<int> doll, int N, int K){
    bool exist = false;
    int minSize = 1000000;
    int start = -1, end = -1, j = -1;
    vector<int> ryan;

    for (int i = 0; i < N; ++i) {
        if (doll[i]==1){
            if (start == -1){  // 처음 등장한 라이언
                start = i;
                ryan.push_back(i);
                j = 0;
                continue;
            }

            if (ryan.size() < K-1 ){  // 두번째 ~ k-1 번째 등장한 라이언
                ryan.push_back(i);
                continue;
            }

            if (ryan.size() >= K){
                start = ryan[++j];
            }
            end = i;
            ryan.push_back(i);
            minSize = min(minSize, end-start+1);

            if(!exist) exist = true;
        }
    }

    if (!exist) return -1;
    else return minSize;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin>>N>>K;

    vector<int> doll(N, 0);
    for (int i = 0; i < N; ++i) {
        cin>>doll[i];
    }

    int answer = getMinSize(doll, N, K);
    cout<<answer;

    return 0;
}
