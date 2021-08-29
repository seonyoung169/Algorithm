#include <iostream>
#include <vector>

// 프로그래머스 자물쇠와 열쇠, level 3, 2020 kakao blind recruitment
using namespace std;

int N, M;

// key 회전 시키기
void rotateKey(vector<vector<int>> & key){
    vector<vector<int>> newKey(M, vector<int>(M, 0));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j<M; j++){
            int originy = M-1-j;
            int originx = i;
            newKey[i][j] = key[originy][originx];
        }
    }

    key = newKey;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int rotation = 0;

    N = lock.size();
    M = key.size();

    int hole = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (lock[i][j] == 0) hole++;
        }
    }

    while (rotation < 4){
        if (rotation > 0) rotateKey(key);

        for (int dy = M-1; dy >= -N+1 ; --dy) {
            for (int dx = M-1; dx >= -N+1 ; --dx) {
                int count = 0;
                bool fail = false;
                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < N; ++j) {
                        int keyY = i + dy, keyX = j + dx;
                        if (keyY>=0 && keyY<M && keyX>=0 && keyX<M && key[keyY][keyX] == 1) {
                            if (lock[i][j] == 0) count++;
                            else {
                                fail = true;
                                i = N;
                                j = N;
                            }
                        }
                    }
                }
                if (!fail && count==hole) return true;
            }
        }
        rotation++;
    }

    return false;
}
