#include <iostream>
#include <vector>

// BOJ 14719 빗물
using namespace std;

int getRain(vector<vector<int>> map){
    int rain = 0;
    int H = map.size();
    int W = map[0].size();

    for (int i = H-1; i >=0 ; i--) {
        // 벽 시작, 종료 여부와 해당 지점 index
        bool start = false, end = false;
        int left = -1, right = -1;

        for (int j = 0; j < W; ++j) {
            if (map[i][j] == 1){  // 벽을 만나면
                if (!start){  // 시작되는 벽이면
                    start = true;
                    left = j;
                } else{  // 끝나는 벽 찾으면
                    end = true;
                    right = j;

                    if (start && end && right-left > 1){  // 두 벽 사이 공간이 있으면
                        rain += right-left-1;
                    }

                    j--; // 다시 종료한 벽부터 탐색해야 
                    start = false;
                    end = false;
                }
            }
        }
    }

    return rain;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H, W;
    cin>>H>>W;

    vector<vector<int>> map(H, vector<int>(W, 0));

    int wall;
    for (int i = 0; i < W; ++i) {
        cin>>wall;
        for (int j = 0; j < wall; ++j) {
            map[H-1-j][i] = 1;
        }
    }

    int rain = getRain(map);
    cout<<rain;

    return 0;
}
