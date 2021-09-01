#include <iostream>
#include <vector>

// 프로그래머스 합승 택시 요금, level 3, 플로이드 와샬 사용 
using namespace std;

vector<vector<int>> map;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    int INF = n*100000 + 1;
    map.assign(n+1, vector<int>(n+1, INF));

    // 지도 완성
    for (int i = 0; i < fares.size(); ++i) {
        map[fares[i][0]][fares[i][1]] = fares[i][2];
        map[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    for (int i = 1; i <= n ; ++i) {
        map[i][i] = 0;
    }

    // floyd warshall
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (map[i][j] > map[i][k] + map[k][j]){
                    map[i][j] =  map[i][k] + map[k][j];
                }
            }
        }
    }

    answer = map[s][a] + map[s][b];
    for (int i = 1; i <= n; ++i) {
        if (i!=s){
            if (answer > map[s][i] + map[i][a] + map[i][b]){
                answer = map[s][i] + map[i][a] + map[i][b];
            }
        }
    }

   return answer;
}
