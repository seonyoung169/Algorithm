#include <string>
#include <vector>
#include <algorithm>

// 프로그래머스 피로도, level 2, 완탐 
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1, N = dungeons.size();
    sort(dungeons.begin(), dungeons.end());
    
    do {
        int count = 0, energy = k;
        for(int i=0; i<N; i++){
            if(energy < dungeons[i][0]) break;
            energy -= dungeons[i][1];
            count++;
        }
        answer = max(answer, count);
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}
