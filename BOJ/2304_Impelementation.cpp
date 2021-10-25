#include <iostream>
#include <vector>

// boj 2304 창고 다각형, 구현, 실버 2
using namespace std;

vector<vector<int>> map(1001, vector<int>(1001, 0));

int getArea(int highest, int first, int last){
    int area = 0;

    for (int i = 0; i < highest; ++i) {
        int start = -1, end = -1;
        for (int j = first; j <= last; ++j) {
            if (map[i][j]==1 ){
                if (start == -1){
                    start = j;
                    end = j;
                }else{
                    end = j;
                }
            }
        }
        area += end-start+1;
    }

    return area;
}

int main() {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int highest = -1, first = 1001, last = -1;
    for (int i = 0; i < N; ++i) {
        int L, H;
        cin>>L>>H;

        if (highest < H) highest = H;
        if (first > L) first = L;
        if (last < L) last = L;

        for (int j = 0; j < H; ++j) {
            map[j][L] = 1;
        }
    }

    cout<<getArea(highest, first, last);

    return 0;
}
