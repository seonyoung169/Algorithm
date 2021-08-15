#include <iostream>
#include <vector>

// BOJ 17144 미세먼지 안녕!, simulation
using namespace std;

int R, C, T;
vector<vector<int>> map;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int upperY[4] = {0, -1, 0, 1};
int upperX[4] = {1, 0, -1, 0};

int bottomY[4] = {0, 1, 0, -1};
int bottomX[4] = {1, 0, -1, 0};

// 현재 location 좌표 기준으로 moveIndex 방향으로 이동할 수 있는지, 이동할 수 있다면 새로운 좌표로 location 변경
bool isMovable(pair<int, int> & location, int & index, bool isUpper){
    int nr, nc;

    if (isUpper){
        nr = location.first + upperY[index];
        nc = location.second + upperX[index];

        if(nr>=0 && nr<R && nc>=0 && nc<C){
            if (map[nr][nc] == -1) return false;

            location.first = nr;
            location.second = nc;
            return true;
        }else {
            if (index < 3) {
                index++;
                nr = location.first + upperY[index];
                nc = location.second + upperX[index];

                if(nr>=0 && nr<R && nc>=0 && nc<C){
                    location.first = nr;
                    location.second = nc;
                    return true;
                }else return false;
            }
            return false;
        }
    }else{
        nr = location.first + bottomY[index];
        nc = location.second + bottomX[index];

        if(nr>=0 && nr<R && nc>=0 && nc<C){
            if (map[nr][nc] == -1) return false;

            location.first = nr;
            location.second = nc;
            return true;
        }else {
            if (index < 3) {
                index++;
                nr = location.first + bottomY[index];
                nc = location.second + bottomX[index];

                if(nr>=0 && nr<R && nc>=0 && nc<C){
                    location.first = nr;
                    location.second = nc;
                    return true;
                }else return false;
            }
            return false;
        }
    }
}

// 정화 단계, 현재 location 기준으로 값을 옮기고 더 나아갈 수 있으면 반복
void clean(pair<int, int> start, bool isUpeer){
    pair<int, int> location = start;
    int temp1 = -1, temp2;
    bool movable = true;
    int moveIndex = 0;

    while (movable){
        if(temp1 == -1) temp1 = 0;

        // location 위치에 새롭게 들어올 먼지 (temp1) 교체, location에 원래 있던 먼지량을 temp1에 다시
        temp2 = map[location.first][location.second];
        map[location.first][location.second] = temp1;
        temp1 = temp2;

        // movable 인지 판단
        if (isUpeer){
            movable = isMovable(location, moveIndex, true);
        }else{
            movable = isMovable(location, moveIndex, false);
        }
    }
}

int getLeftDust(vector<vector<int>> diffuse, pair<int, int> cleaner){
    int totalDust;

    while (T > 0){
        T--;
        totalDust = 0;

        // 1. 확산
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if(diffuse[i][j] >= 0){
                    int diffuseSum = 0, neighbor = 0;

                    //인접한 4방향으로부터 받는 먼지가 있는지, 이웃 수가 몇명인지 계산
                    for (int k = 0; k < 4; ++k) {
                        int nr = i + dy[k];
                        int nc = j + dx[k];

                        if (nr>=0 && nr<R && nc>=0 && nc<C && map[nr][nc] != -1){
                            diffuseSum +=  diffuse[nr][nc];
                            neighbor++;
                        }
                    }

                    // 이웃에게 확산되는 먼지 반영, 인접한 칸으로부터 받는 먼지 반영
                    if (diffuse[i][j] == 0){
                        map[i][j] += diffuseSum;
                    }else{
                        map[i][j] = map[i][j] - (diffuse[i][j] * neighbor) + diffuseSum;
                    }
                }
            }
        }

        // 2. 정화
        clean(make_pair(cleaner.first, 1), true);
        clean(make_pair(cleaner.second, 1), false);

        // 3. diffuse 배열 재계산, 전체 먼지량 계산
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (map[i][j] == -1){
                    diffuse[i][j] =  -1;
                } else{
                    totalDust += map[i][j];
                    if (map[i][j] > 0){
                        diffuse[i][j] = map[i][j]/5;
                    } else{
                        diffuse[i][j] = 0;
                    }
                }
            }
        }
    }

    return totalDust;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>R>>C>>T;

    map.assign(R, vector<int>(C, 0));
    vector<vector<int>> diffuse(R, vector<int>(C, 0)); // 각 칸에서 확산될 수 있는 양 계산
    pair<int, int> cleaner = make_pair(-1, -1);  // 공기청정기 위치 (행)

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin>>map[i][j];
            if (map[i][j] == -1){
                if(cleaner.first == -1) {
                    cleaner.first = i;
                }else{
                    cleaner.second = i;
                }
                diffuse[i][j] = -1;
            }

            if (map[i][j] > 0){
                diffuse[i][j] = map[i][j]/5;
            }
        }
    }

    int left = getLeftDust(diffuse, cleaner);
    cout<<left;

    return 0;
}
