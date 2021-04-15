#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// BOJ 2667번 BFS 이용
using namespace std;

void BFS(vector<vector<int>> & map, int row, int col, int & house){
    if (row < 0 || row > map.size()-1 || col < 0 || col > map.size()-1) return;
    if (map[row][col] == 0 || map[row][col] == 2) return;

    if (map[row][col] == 1) map[row][col] = 2;

    house++;
    BFS(map, row-1, col, house);
    BFS(map, row+1, col, house);
    BFS(map, row, col-1, house);
    BFS(map, row, col+1, house);
}

int main() {
    int town = 0;
    int N;
    cin>>N;

    vector<vector<int>> map(N, vector<int>());
    vector<int> houseCount;
    for (int i = 0; i < N ; ++i) {
        string numstr;
        cin>>numstr;
        for (int j = 0; j <N ; ++j) {
            map[i].push_back(numstr[j]-'0');
        }
    }

    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N ; ++col) {
            int house = 0;
            if (map[row][col] == 1){
                town++;
                BFS(map, row, col, house);
                houseCount.push_back(house);
            }
        }
    }

    sort(houseCount.begin(), houseCount.end());

    cout<<town<<'\n';
    for (int i = 0; i < houseCount.size() ; ++i) {
        cout<<houseCount[i]<<'\n';
    }

    return 0;
}
