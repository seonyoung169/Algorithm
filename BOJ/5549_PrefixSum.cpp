#include <iostream>
#include <algorithm>
#include <vector>

// boj 5549 행성 탐사, 누적합, 골드 5 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, T;
    cin>>N>>M>>T;
    
    vector<vector<string>> map(N+1, vector<string>(M+1, ""));
    vector<vector<int>> sumJ(N+1, vector<int>(M+1, 0));
    vector<vector<int>> sumO(N+1, vector<int>(M+1, 0));
    vector<vector<int>> sumI(N+1, vector<int>(M+1, 0));

    for (int i = 1; i <= N; ++i) {
        string row;
        cin>>row;

        for (int j = 1; j <= M; ++j) {
            map[i][j] = row[j-1];
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            sumJ[i][j] += sumJ[i][j-1];
            sumO[i][j] += sumO[i][j-1];
            sumI[i][j] += sumI[i][j-1];

            if(map[i][j] == "J") sumJ[i][j] += 1;
            else if (map[i][j] == "O") sumO[i][j] += 1;
            else sumI[i][j] += 1;
        }
    }

    for (int j = 1; j <= M; ++j) {
        for (int i = 1; i <= N; ++i) {
            sumJ[i][j] += sumJ[i-1][j];
            sumO[i][j] += sumO[i-1][j];
            sumI[i][j] += sumI[i-1][j];
        }
    }

    for (int i = 0; i < T; ++i) {
        int r1, c1, r2, c2;
        cin>>r1>>c1>>r2>>c2;

        int resultJ = sumJ[r2][c2] - sumJ[r2][c1-1] - sumJ[r1-1][c2] + sumJ[r1-1][c1-1];
        int resultO = sumO[r2][c2] - sumO[r2][c1-1] - sumO[r1-1][c2] + sumO[r1-1][c1-1];
        int resultI = sumI[r2][c2] - sumI[r2][c1-1] - sumI[r1-1][c2] + sumI[r1-1][c1-1];

        cout<<resultJ<<" "<<resultO<<" "<<resultI<<'\n';
    }

    return 0;
}
