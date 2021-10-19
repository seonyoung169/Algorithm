#include <iostream>
#include <vector>

// boj 20056 마법사 상어아 파이어볼, 골드 5, simulation
using namespace std;

int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,1,1,1,0,-1,-1,-1};

typedef struct fireball {
    int mass;
    int speed;
    int dir;

    fireball(int m, int s, int d) {
        this->mass = m;
        this->speed = s;
        this->dir = d;
    }
}FireBall;

vector<vector<vector<FireBall>>> map;

int moveFireBall(int N, int M, int K){
    int left_mass = 0;
    int order = K;

    while (order>0){
        order--;
        vector<vector<vector<FireBall>>> moved(N+1, vector<vector<FireBall>>(N+1));

        // 1. 이동
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (map[i][j].empty()) continue;

                for (int k = 0; k < map[i][j].size(); ++k){
                    int m = map[i][j][k].mass;
                    int s = map[i][j][k].speed;
                    int d = map[i][j][k].dir;

                    int nr = i + dy[d] * (s % N);
                    if (nr<1) nr += N;
                    if (nr>N) nr -= N;

                    int nc = j + dx[d] * (s % N);
                    if(nc<1) nc += N;
                    if (nc>N) nc -= N;

                    moved[nr][nc].push_back(FireBall(m, s, d));
                }
            }
        }

        // 2. 정리
        map.clear();
        map.assign(N+1, vector<vector<FireBall>>(N+1));

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (moved[i][j].empty()) continue;

                if (moved[i][j].size()==1){
                    map[i][j].push_back(FireBall(moved[i][j][0].mass,moved[i][j][0].speed,moved[i][j][0].dir));
                    if(order==0) left_mass += moved[i][j][0].mass;
                    continue;
                }

                int mass_sum = 0, speed_sum = 0;
                bool same_dir = true;

                for (int k = 0; k < moved[i][j].size(); ++k) {
                    mass_sum += moved[i][j][k].mass;
                    speed_sum += moved[i][j][k].speed;

                    if(k>0 && same_dir){
                        if (moved[i][j][k-1].dir%2 != moved[i][j][k].dir%2) same_dir = false;
                    }

                }

                mass_sum = mass_sum/5;
                if (mass_sum == 0) continue;

                speed_sum = speed_sum/moved[i][j].size();

                int dir_base = -1;
                if (same_dir) dir_base = 0;
                else dir_base = 1;

                for (int k = 0; k <=6 ; k += 2) {
                    map[i][j].push_back(FireBall(mass_sum, speed_sum, dir_base+k));
                    if (order==0) left_mass += mass_sum;
                }
            }
        }

    }

    return left_mass;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin>>N>>M>>K;

    map.assign(N+1, vector<vector<FireBall>>(N+1));

    int r, c, m, s, d;
    for (int i = 0; i < M; ++i) {
        cin>>r>>c>>m>>s>>d;
        map[r][c].push_back(FireBall(m, s, d));
    }

    cout<<moveFireBall(N,M,K);

    return 0;
}
