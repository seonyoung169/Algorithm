#include <iostream>
#include <vector>
#include <algorithm>

// BOJ 21608 상어 초등학교, 구현 문제 
using namespace std;

int r[4] = {-1, 0,1,0};
int c[4] = {0, 1, 0, -1};
int points[5] = {0,1,10,100,1000};

vector<vector<int>> seat;

// 행, 열 빠른 순으로 정렬
bool byRowCol(pair<int, int> a, pair<int, int> b){
    if (a.first == b.first){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

bool bySecondDesc(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return a.second > b.second;
}

// 좋아하는 친구가 있는지
bool isPrefStudents(int N, int row, int col, vector<int> pref){
    if (row>= 0 && row < N && col >=0 && col < N && seat[row][col] != -1){
        int neigh = seat[row][col];

        for (int i = 0; i < 4; ++i) {
            if (pref[i] == neigh) return true;
        }
    }
    return false;
}

vector<pair<int, int>> checkCondition1(int N, int student, vector<int> pref){
    // 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.

    vector<pair<int, int>> confirmedSeat;
    vector<pair<pair<int, int>, int>> friendCount;  // 각 자리별로 주변에 좋아하는 친구가 몇명 있는지

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (seat[i][j] == -1) { // 해당 자리가 빈 자리이면 좌우양옆 네 칸을 확인합니당

                int friends = 0;
                for (int k = 0; k < 4; ++k) {
                    int row = i + r[k];
                    int col = j + c[k];


                    if (isPrefStudents(N, row, col, pref)) { // 좋아하는 학생이 주변에 앉아있는 경우
                        friends++;
                    }
                }
                friendCount.push_back(make_pair(make_pair(i, j), friends));
            }
        }
    }

    // seatAndCount 를 second 값 기준으로 desc sort
    sort(friendCount.begin(), friendCount.end(), bySecondDesc);

    // 상위 n개 자리 추려서 return
    confirmedSeat.push_back((make_pair(friendCount[0].first.first, friendCount[0].first.second)));
    int max = friendCount[0].second;

    for (int i = 1; i < friendCount.size(); ++i) {
        if (friendCount[i].second == max) {
            confirmedSeat.push_back(make_pair(friendCount[i].first.first, friendCount[i].first.second));
        }else break;
    }

    return confirmedSeat;
}

vector<pair<int, int>> checkCondition2(int N, vector<pair<int, int>> candidates1){
    vector<pair<pair<int, int>, int>> blankCount;
    vector<pair<int, int>> candidates2;

    for (int i = 0; i < candidates1.size(); ++i) {
        int blank = 0;
        for (int j=0; j<4; j++){
            // 인접 칸의 행, 열
            int row = candidates1[i].first + r[j];
            int col = candidates1[i].second + c[j];

            if (row>= 0 && row < N && col >=0 && col < N
                && seat[row][col] == -1) {  // 인접 칸이 비어 있으면 비어있는 칸 count
                blank++;
            }
        }
        blankCount.push_back(make_pair(candidates1[i], blank));
    }

    // 주변 칸 중 빈 칸이 많은 순으로 정렬
    sort(blankCount.begin(), blankCount.end(), bySecondDesc);

    // 상위 n 개 칸 추려서 return
    candidates2.push_back(blankCount[0].first);
    int max = blankCount[0].second;

    for (int i = 1; i < blankCount.size(); ++i) {
        if (blankCount[i].second == max){
            candidates2.push_back(blankCount[i].first);
        } else break;
    }

    return candidates2;
}


void sitStudents(int N, vector<pair<int, vector<int>>> preference, vector<pair<int, int>> & finalSeatOrder) {

    for(int i=0; i<preference.size(); i++) {
        int student = preference[i].first;
        vector<int> pref = preference[i].second;

        // 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
        vector<pair<int ,int>> candidates1 = checkCondition1(N, student, pref);

        // 1단계를 만족하는 자리가 하나일 때
        if (candidates1.size() == 1) {
            int R = candidates1[0].first;
            int C = candidates1[0].second;
            seat[R][C] = student;
            finalSeatOrder.push_back(make_pair(R, C));
            continue;
        }

        // 1단계를 만족하는 자리가 여러개일 때 candidates1 중에서 2단계 실행
        vector<pair<int, int>> candidates2 = checkCondition2(N, candidates1);
        if (candidates2.size() == 1) {
            int R = candidates2[0].first;
            int C = candidates2[0].second;
            seat[R][C] = student;
            finalSeatOrder.push_back(make_pair(R, C));
            continue;
        }

        // 2단계를 만족하는 자리가 여러개이면 candidates2 중에서 행, 열이 가장 작은 자리에 앉힘
        sort(candidates2.begin(), candidates2.end(), byRowCol);
        int finalR = candidates2[0].first;
        int finalC = candidates2[0].second;
        seat[finalR][finalC] = student;
        finalSeatOrder.push_back(make_pair(finalR, finalC));
    }

}

int getSatisfying(int N, vector<pair<int, vector<int>>> preference, vector<pair<int, int>> finalSeatOrder){
    int satisfied = 0;

    for (int i = 0; i < finalSeatOrder.size(); ++i) {
        int seatR = finalSeatOrder[i].first;
        int seatC = finalSeatOrder[i].second;
        vector<int> pref = preference[i].second;

        int friendCount = 0;
        // 각 자리 좌우양옆으로 좋아하는 친구 count
        for (int j = 0; j < 4; ++j) {
            int row = seatR + r[j];
            int col = seatC + c[j];

            if (isPrefStudents(N, row, col, pref)) {
                friendCount++;
            }
        }

        // 점수 더하기
        satisfied += points[friendCount];
    }


    return satisfied;
}

int main() {
    int N;
    cin >> N;

    int seats = N*N;
    vector<pair<int, vector<int>>> preference(seats);
    vector<pair<int, int>> finalSeatOrder;

    for (int i = 0; i < seats; ++i) {
        cin>>preference[i].first;
        int num;
        for (int j = 0; j < 4; ++j) {
            cin>>num;
            preference[i].second.push_back(num);
        }
    }

    // 모든 자리 -1로 setting
    seat.assign(N, vector<int>(N, -1));

    sitStudents(N, preference, finalSeatOrder);

    int answer = getSatisfying(N, preference, finalSeatOrder);

    cout<<answer;

    return 0;
}
