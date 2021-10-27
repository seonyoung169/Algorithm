#include <iostream>
#include <vector>

// boj 1913 달팽이, 구현, 실버 5
using namespace std;

vector<vector<int>> map;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

void makeMap(int N){
    int count = 1;

    map[N/2][N/2] = count;
    count++;

    for (int i = 1; i <N/2+1 ; ++i) {
        int from = N/2-i, to = N/2+i;
        int dir = 0;
        pair<int,int> cur = {N/2-i, N/2-i+1};

        while (count<=N*N){
            map[cur.first][cur.second] = count;
            count++;
            if (count>N*N) break;

            int nr = cur.first + dy[dir];
            int nc = cur.second + dx[dir];

            if (nr<from || nr>to || nc<from || nc>to){
                if (dir<3){
                    dir++;
                    cur.first += dy[dir];
                    cur.second += dx[dir];
                }else{
                    break;
                }
            }else{
                cur = {nr, nc};
            }
        }
    }
}

int main() {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    cin>>N>>num;

    map.assign(N, vector<int>(N, -1));

    makeMap(N);

    int row = -1, col = -1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout<<map[i][j]<<' ';
            if(map[i][j] == num){
                row = i+1;
                col = j+1;
            }
        }
        cout<<'\n';
    }
    cout<<row<<' '<<col;


    return 0;
}
