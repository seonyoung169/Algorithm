#include <iostream>
#include <vector>
#include <algorithm>

#define INF 100000

// BOJ 21278 호석이 두마리 치킨, 골드 5, Folyd Warshall & Brute Force
using namespace std;

int N;
vector<vector<int>> map;

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    if (a.second == b.second){
        if (a.first.first == b.first.first){
            return a.first.second < b.first.second;
        }else{
            return a.first.first < b.first.first;
        }
    }else{
        return a.second<b.second;
    }
}

vector<pair<int, int>> getCombinations(int n) {
    vector<pair<int, int>> combinations;
    vector<bool> select;

    for (int i = 0; i < n-2; ++i) {
        select.push_back(false);
    }
    select.push_back(true);
    select.push_back(true);


    do{
        bool first = false;
        pair<int, int> combi;
        for (int i = 0; i < n; ++i) {
            if (select[i]) {
                if (!first) {
                    first = true;
                    combi.first = i+1;
                }else{
                    combi.second = i+1;
                    combinations.push_back(combi);
                    break;
                }
            }
        }
    }while (next_permutation(select.begin(), select.end()));

    return combinations;
}

void floydWarshall(vector<vector<int>> & shortest) {
    for (int k = 1; k <= N ; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (shortest[i][j] > shortest[i][k] + shortest[k][j]){
                    shortest[i][j] = shortest[i][k] + shortest[k][j];
                }
            }

        }
    }
}

void findBestPlace(){
    vector<pair<int, int>> combinations = getCombinations(N);
    vector<pair<pair<int, int>, int>> candidates;
    floydWarshall(map);


    // 모든 조합에 대해서 왕복 거리 합 구하기
    for (int i = 0; i < combinations.size(); ++i) {
        int chicken1 = combinations[i].first;
        int chicken2 = combinations[i].second;

        int totalCost = 0;
        for (int j = 1; j <= N; ++j) {
            if (chicken1 == j || chicken2 == j) continue;
            totalCost += 2*min(map[j][chicken1], map[j][chicken2]);
        }
        candidates.push_back(make_pair(combinations[i], totalCost));
    }

    sort(candidates.begin(), candidates.end(), comp);

    cout<<candidates[0].first.first<<' '<<candidates[0].first.second<<' '<<candidates[0].second;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, a, b;
    cin>>N>>M;

    map.assign(N+1, vector<int>(N+1, INF));
    for (int i = 1; i <= N; ++i) {
        map[i][i] = 0;
    }
    for(int i=0; i<M; i++){
        cin>>a>>b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    findBestPlace();

    return 0;
}
