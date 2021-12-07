#include <iostream>
#include <vector>

// boj 22858 원상 복구, 실버 3, 구현
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin>>N>>K;

    vector<int> S(N+1,0);
    vector<int> D(N+1, 0);

    for (int i = 1; i <= N; ++i) cin>>S[i];
    for (int i = 1; i <= N ; ++i) cin>>D[i];

    vector<int> rewind(N+1, 0);
    while (K>0){
        K--;
        for (int i = 1; i <= N; ++i) {
            int origin_index = D[i];
            int num = S[i];
            rewind[origin_index] = num;
        }

        S = rewind;
    }

    rewind.clear();

    for (int i = 1; i <= N; ++i) {
        cout<<S[i]<<' ';
    }
    cout<<'\n';

   return 0;
}
