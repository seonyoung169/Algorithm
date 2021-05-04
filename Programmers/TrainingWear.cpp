#include <iostream>
#include <string>
#include <vector>

//프로그래머스 고득점 kit - greedy 체육복, level 1
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> wearCount(n+1, 1);
    vector<bool> isLost(n+1, false);

    for(int i=0; i<reserve.size(); i++){
        int idx = reserve[i];
        wearCount[idx] += 1;
    }

    for(int i=0; i<lost.size(); i++){
        int idx = lost[i];
        wearCount[idx] -= 1;
    }


    for(int i=1; i<wearCount.size(); i++){
        if(wearCount[i] == 0){
            int pre = i-1;
            int post = i+1;

            if(pre>=1 && wearCount[pre] == 2){
                wearCount[i] += 1;
                wearCount[pre] -= 1;
            }else{
                if(post<=n && wearCount[post] == 2){
                    wearCount[i] += 1;
                    wearCount[post] -= 1;
                }
            }
        }
    }

    for (int i=1; i<=n; i++){
        if (wearCount[i] >= 1) answer++;
    }


    return answer;
}
int main() {
    int ans;

    ans = solution(3,{3}, {1});

    cout<<ans;

    return 0;
}
