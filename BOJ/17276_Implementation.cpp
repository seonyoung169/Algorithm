#include <iostream>
#include <vector>

// boj 17276 배열 돌리기, 실버 2, 구현 
using namespace std;

void rotate(int N, int d, vector<vector<int>> origin){
    vector<vector<int>> moved = origin;

    while (d>0) {
        for (int i = 0; i < N; ++i) {
            moved[i][N/2] = origin[i][i];
            moved[i][i] = origin[N/2][i];
            moved[N/2][i] = origin[N-1-i][i];
            moved[N-1-i][i] = origin[N-1-i][N/2];
        }

        origin = moved;
        d--;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout<<origin[i][j]<<' ';
        }
        cout<<'\n';
    }

}

int main() {
    int T;
    cin>>T;


    while (T>0){
        int N, d;
        cin>>N>>d;

        if (d<0) d += 360;
        d /= 45;

        vector<vector<int>> map(N, vector<int>(N,0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin>>map[i][j];
            }
        }

        rotate(N, d, map);

        T--;
    }


    return 0;
}
