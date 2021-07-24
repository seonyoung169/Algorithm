#include <iostream>
#include <vector>
#include <queue>

// BOJ 1520 내리막길, BFS
using namespace std;

// 각 지점의 높이 값과 해당 좌표 값을 함께 저장, 구조체 사용
typedef struct point {
    int height;
    pair<int, int> coor;

    point() {
        height = 0;
    };

    point(int h, pair<int, int> c){
        height = h;
        coor = c;
    }

} Point;

// 우선순위 큐 정렬 기준, 높이가 높은 순서대로
struct comp {
    bool operator()(Point a, Point b){
        return a.height < b.height;
    }
};

int dy[4] = {-1, 0, 1,0};
int dx[4] = {0, 1, 0, -1};

int getPathToExit(int M, int N, vector<vector<int>> map){
    vector<vector<int>> dp(M, vector<int>(N,0));  // 경로 수 기록
    pair<int, int> destination = make_pair(M-1, N-1);  // 목적지
    priority_queue<Point, vector<Point>, comp> pq;

    queue<pair<int, int>> points; // 탐색할 좌표들

    pair<int, int> location;  // 현재 확인하고 있는 위치

    pq.push(Point (map[0][0],make_pair(0,0)));
    dp[0][0] = 1;

    while (!pq.empty()){
        location = pq.top().coor;
        pq.pop();

        if (location == destination){
            continue;
        }

        int height = map[location.first][location.second];

        for (int i = 0; i < 4; ++i) {  // 위쪽 칸부터 시계 방향으로 확인
            int row = location.first + dy[i];
            int col = location.second + dx[i];

            if (row >= 0 && row < M && col >= 0 && col < N){
                if (map[row][col] < height){
                    if (dp[row][col] == 0){  // 처음 dp값을 확인하게 될 때에만 pq.push
                        pq.push(Point(map[row][col], make_pair(row,col)));
                    }
                    dp[row][col] += dp[location.first][location.second];
                }
            }
        }
    }


    return dp[M-1][N-1];
}

int main() {
    int M, N;
    cin>>M>>N;

    vector<vector<int>> map(M, vector<int>(N, 0));
    for (int i = 0; i < M; ++i) {
        for (int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }

    int answer = getPathToExit(M, N, map);

    cout<<answer;

    return 0;
}
