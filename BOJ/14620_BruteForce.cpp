#include <iostream>
#include <vector>
#include <algorithm>

// boj 14620 꽃길, 실버 2, brute force 
using namespace std;

int N;
vector<vector<int>> board;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

vector<vector<pair<int, int>>> makeCombi(){
    vector<vector<pair<int, int>>> result;
    vector<pair<int, int>> candidates;

    for (int i = 1; i <= N-2 ; ++i) {
        for (int j = 1; j <= N-2 ; ++j) candidates.push_back({i,j});
    }
    sort(candidates.begin(), candidates.end());

    vector<bool> check = {true, true, true};
    for (int i = 0; i < candidates.size()-3; ++i) check.push_back(false);
    
    do{
        vector<pair<int, int>> temp;
        for (int i = 0; i < candidates.size(); ++i) {
            if (check[i]) temp.push_back(candidates[i]);
        }

        result.push_back(temp);
    }while (prev_permutation(check.begin(), check.end()));

    return result;
}

int check(vector<pair<int, int>> points){
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    int sum = 0;

    for (int i = 0; i < points.size(); ++i) {
        visited[points[i].first][points[i].second] = true;
        sum += board[points[i].first][points[i].second];

        for (int j = 0; j < 4; ++j) {
            int ny = points[i].first + dy[j];
            int nx = points[i].second + dx[j];

            if (visited[ny][nx]) return -1;

            visited[ny][nx] = true;
            sum += board[ny][nx];
        }
    }

    return sum;
}

int getMinCost(){
    int min = 200*15;
    vector<vector<pair<int, int>>> combi = makeCombi();

    for (int i = 0; i < combi.size(); ++i) {
        vector<pair<int, int>> points = combi[i];
        int sum = check(points);
        if (sum != -1 && min > sum) min = sum;
    }

    return min;
}

int main() {
    cin>>N;
    board.resize(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cin>>board[i][j];
    }

    cout<<getMinCost();

    return 0;
}
