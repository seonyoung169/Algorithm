#include <iostream>
#include <vector>
#include <algorithm>

// 프로그래머스 땅따먹기, level 2, dp 사용
using namespace std;

bool desc(pair<int, int> a, pair<int ,int> b){
    return a.first > b.first;
}

int solution(vector<vector<int>> land)
{
    int answer = 0, lastCol;
    int N = land.size();

    vector<vector<pair<int, int>>> dpLand(N, vector<pair<int, int>>());

    for (int j = 0; j < 4 ; ++j) {
        dpLand[0].push_back(make_pair(land[0][j], j));
    }

    for (int i=1; i<N; i++){
        sort(dpLand[i-1].begin(), dpLand[i-1].end(), desc);

        for (int j = 0; j < 4 ; ++j) {
            int point = land[i][j];
            for (int k = 0; k < 4; ++k) {
                if (dpLand[i-1][k].second != j){
                    int dummy = dpLand[i-1][k].first;
                    dpLand[i].push_back(make_pair(dummy + point, j));
                    break;
                }
            }
        }
    }

    sort(dpLand[N-1].begin(), dpLand[N-1].end(), desc);
    answer = dpLand[N-1][0].first;

    return answer;
}

int main() {
    int ans;

    ans = solution({{4,3,2,1},{2,2,2,1},{6,6,6,4}, {8,7,5,6}});

    return 0;
}
