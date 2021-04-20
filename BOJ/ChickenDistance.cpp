

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

// BOJ 15686 치킨거리, 조합 이용
using namespace std;

int calculateDistance(pair<int, int> a, pair<int, int> b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}

int getChickenDistance(vector<pair<int, int>> combinations, int m, vector<pair<int,int>> house){
    int minDistance = 2147483647;

    int start = 0;
    while (start < combinations.size()){
        int distance = 0;

        vector<pair<int, int>> chicken;

        for (int j = start; j < start + m; j++){
            chicken.push_back(combinations[j]);
        }
        start += m;

        for (int k = 0; k < house.size(); ++k) {
            int min = 2147483647;
            for (int h = 0; h<chicken.size(); h++){
                int cal = calculateDistance(house[k], chicken[h]);
                if (min > cal) min = cal;
            }
            distance += min;
        }

        if (minDistance > distance) {
            minDistance = distance;
        }
    }

    return minDistance;
}

vector<pair<int,int>> getCombination(vector<pair<int,int>> chicken, int M) {
    int len = chicken.size();

    vector<pair<int, int>> combinations;

    vector<bool> check(len - M, false);
    check.insert(check.end(), M, true);

    do {
        for (int j = 0; j < len; j++) {
            if (check[j]) {
                combinations.push_back(chicken[j]);
            }
        }
    } while (next_permutation(check.begin(), check.end()));

    return combinations;
}

int main() {
    int N, M;
    cin>>N>>M;

    vector<vector<int>> city(N+1, vector<int>(N+1, 0));
    vector<pair<int, int>> house;
    vector<pair<int, int>> chicken;
    vector<pair<int, int>> combinations;

    for (int i=1; i<=N; i++){
        for (int j = 1; j <= N; ++j) {
            cin>>city[i][j];

            if (city[i][j] == 1){
                house.push_back(make_pair(i,j));
                continue;
            }
            if (city[i][j] == 2){
                chicken.push_back(make_pair(i,j));
                continue;
            }
        }
    }

    combinations = getCombination(chicken, M);


    int answer = getChickenDistance(combinations, M, house);

    cout<<answer<<'\n';

    return 0;
}
