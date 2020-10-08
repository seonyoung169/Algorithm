#include <iostream>
#include <vector>
#include <algorithm>

// BOJ 1149 RGB거리, dp 이용 맞음! 
using namespace std;

int memozation[1001][3];
vector<vector<int>> prices;

int main(){
    int N, red, green, blue;
    cin>>N;

    for(int i=0; i<N; i++){
        vector<int> temp;
        cin>>red>>green>>blue;

        temp.push_back(red);
        temp.push_back(green);
        temp.push_back(blue);

        prices.push_back(temp);
    }

    //첫번째 집 색칠 비용 초기화
    memozation[1][0] = prices[0][0];
    memozation[1][1] = prices[0][1];
    memozation[1][2] = prices[0][2];

    //dp 적용
    for(int i=2; i<=N; i++){
        memozation[i][0] = prices[i-1][0] + min(memozation[i-1][1], memozation[i-1][2]);
        memozation[i][1] = prices[i-1][1] + min(memozation[i-1][0], memozation[i-1][2]);
        memozation[i][2] = prices[i-1][2] + min(memozation[i-1][0], memozation[i-1][1]);
    }

    int min = memozation[N][0];
    for(int i=1; i<=2; i++){
        if(min > memozation[N][i]){
            min = memozation[N][i];
        }
    }

    cout<<min<<'\n';

    return 0;
}
