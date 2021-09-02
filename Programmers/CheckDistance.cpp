#include <string>
#include <vector>

// 프로그래머스 거리두기 확인하기, level 2, 2020 카카오 인턴십
using namespace std;

int dist1_row[4] = {-1,0,1,0};
int dist1_col[4] = {0,1,0,-1};

int dist2_close_row[4] = {-1,1,1,-1};
int dist2_close_col[4] = {1,1,-1,-1};

int dist2_far_row[4] = {-2,0,+2, 0};
int dist2_far_col[4] = {0,2,0,-2};

vector<vector<char>> room;
vector<vector<bool>> isChecked;

bool isDist1Safe(int py, int px){  // 맨해튼 거리 1 검사
    for (int i = 0; i < 4; ++i) {
        int ny = py + dist1_row[i];
        int nx = px + dist1_col[i];

        if(ny>=0 && ny<5 && nx>=0 && nx<5 && room[ny][nx] == 'P') return false;
    }
    return true;
}

bool isDist2CloseSafe(int py, int px){  // 맨해튼 거리 2 가까운 4자리 검사
    for (int i = 0; i < 4; ++i){
        int ny = py + dist2_close_row[i];
        int nx = px + dist2_close_col[i];

        if(ny>=0 && ny<5 && nx>=0 && nx<5 && room[ny][nx] == 'P'){
            if (isChecked[ny][nx]) continue;
            if (!(room[ny][px] == 'X' && room[py][nx] == 'X')) return false;
            else isChecked[ny][nx] = true;
        }
    }
    return true;
}

bool isDist2FarSafe(int py, int px){
    for (int i = 0; i < 4; ++i){
        int ny = py + dist2_far_row[i];
        int nx = px + dist2_far_col[i];

        if(ny>=0 && ny<5 && nx>=0 && nx<5 && room[ny][nx] == 'P'){
            if (isChecked[ny][nx]) continue;
            if (room[(py+ny)/2][(px+nx)/2] != 'X') return false;
            else isChecked[ny][nx] = true;
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < 5; ++i) {
        room.clear();
        room.assign(5, vector<char>(5));

        isChecked.clear();
        isChecked.assign(5, vector<bool>(5));

        for (int j = 0; j < 5; ++j) {
            string row = places[i][j];
            for (int k = 0; k < 5; ++k) {
                room[j][k] = row[k];
            }
        }

        bool isRoomSafe = true;
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k <5 ; ++k) {
                if (room[j][k] == 'P'){  // 사람이면 주변 검사
                    if (!isDist1Safe(j, k) || !isDist2CloseSafe(j,k) || !isDist2FarSafe(j, k)){
                        isRoomSafe = false;
                        j=5;
                        break;
                    }else{
                        isChecked[j][k] = true;
                    }
                }
            }
        }

        if (isRoomSafe) answer.push_back(1);
        else answer.push_back(0);
    }


    return answer;
}
