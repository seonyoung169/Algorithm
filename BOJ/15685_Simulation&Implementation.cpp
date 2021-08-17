#include <iostream>
#include <vector>

// BOJ 15685 드레곤 커브, simulation
using namespace std;

int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};;

vector<vector<int>> map(101, vector<int>(101, 0));

void drawDragonCurve(int x, int y, int dir, int gen){
    vector<int> directions;
    directions.push_back(dir);

    pair<int, int> last = make_pair(y+dy[dir], x+dx[dir]);
    map[y][x] = 1;
    map[last.first][last.second] = 1;

    while (gen > 0){
        int size = directions.size();

        for (int i = size-1; i >= 0; i--) {  // 새로운 방향 추가
            directions.push_back((directions[i]+1)%4);
        }

        for (int i = size; i < 2*size; ++i) {
            last.first += dy[directions[i]];
            last.second += dx[directions[i]];
            map[last.first][last.second] = 1;
        }
        gen--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, x, y, dir, gen;
    cin>>N;

    for (int i = 0; i < N; ++i) {
        cin>>x>>y>>dir>>gen;
        drawDragonCurve(x, y, dir, gen);
    }

    int box = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (map[i][j]==1){
                if (map[i][j+1]==1 && map[i+1][j] && map[i+1][j+1]) box++;
            }
        }
    }

    cout<<box;

    return 0;
}
