#include <iostream>

// BOJ 10989번 - 계수 정렬 이용해서 풀기, 맞았습니다!
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, temp, count[10001] = {0};
    int cnt = 0;

    cin>>N;

    for(int i=0; i<N; i++){
        cin>>temp;
        count[temp] += 1;
    }

    for(int i = 1; i<=10001; i++){
        if(count[i] != 0){
            for(int j=0; j<count[i]; j++){
                cout<<i<<'\n';
                cnt++;
            }
        }
        if(cnt >= N) break;
    }
    return 0;
}
