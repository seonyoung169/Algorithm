#include <iostream>
#include <vector>
#include <queue>

// boj 2636 치즈, 골드 5, BFS 사용 
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

vector<vector<int>> plate;

pair<int,int> countTime(int R, int C, int cheese){
    int time = 0;
    int lastCheese = 0;

    while (cheese>0){
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        queue<pair<int, int>> blank;

        visited[0][0] = true;
        blank.push({0,0});

        vector<pair<int, int>> edge;

        while (!blank.empty()){
            pair<int, int> cur = blank.front();
            blank.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = cur.first + dy[i];
                int nc = cur.second + dx[i];

                if (nr>=0 && nr<R && nc>=0 && nc<C && !visited[nr][nc]){
                    if (plate[nr][nc]==0){
                        visited[nr][nc] = true;
                        blank.push({nr, nc});
                    }else{
                        visited[nr][nc] = true;
                        edge.push_back({nr, nc});
                    }
                }
            }
        }

        for (int i = 0; i < edge.size(); ++i) {
            plate[edge[i].first][edge[i].second] = 0;
        }
        if (edge.size() >= cheese) lastCheese = cheese;
        cheese -= edge.size();
        time++;
    }

    return make_pair(time, lastCheese);
}

int main() {
    int R, C;
    cin>>R>>C;

    int cheese = 0;

    plate.assign(R, vector<int>(C, -1));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin>>plate[i][j];
            if (plate[i][j] == 1) cheese++;
        }
    }

    pair<int, int> answer = countTime(R, C, cheese);

    cout<<answer.first<<'\n';
    cout<<answer.second<<'\n';

    return 0;
}
