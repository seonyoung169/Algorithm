#include <iostream>
#include <vector>

//BOJ 2579 계단 오르기 - DP 사용, 맞음!
using namespace std;

int stagePoint[301];
vector<int> stairs(301,0);

int main(){
    int N, num;
    cin>>N;

    for(int i=1; i<=N; i++){
        cin>>num;
        stairs[i] = num;
    }

    stagePoint[1] = stairs[1];
    stagePoint[2] = stairs[1] + stairs[2];
    stagePoint[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);

    if(N > 3){
        for(int i=4; i<=N; i++){
            stagePoint[i] = stagePoint[i-3] + stairs[i-1] + stairs[i];
            int temp = stagePoint[i-2] + stairs[i];
            if(temp > stagePoint[i] ){
                stagePoint[i] = temp;
            }
        }
    }

    cout<<stagePoint[N]<<'\n';

    return 0;
}
