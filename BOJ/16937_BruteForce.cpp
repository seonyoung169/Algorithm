#include <iostream>
#include <vector>
#include <algorithm>

// boj 16937 두 스티커, 실버 3, 완전 탐색 
using namespace std;

int H,W,N;

struct Sticker {
    int w;
    int h;
    int idx;
    Sticker(int w, int h, int i) : w(w), h(h), idx(i) {};
};

vector<Sticker> stickers;

vector<vector<Sticker>> makeCombi(){
    vector<vector<Sticker>> combinations;

    vector<bool> flag(stickers.size()-2, false);
    for (int i = 0; i < 2; ++i) flag.push_back(true);

    do {
        vector<Sticker> combi;
        for (int i = 0; i < flag.size(); ++i) {
            if (flag[i]) combi.push_back(stickers[i]);
        }

        if (combi[0].idx != combi[1].idx) combinations.push_back(combi);

    }while (next_permutation(flag.begin(), flag.end()));

    return combinations;
}

bool possible(vector<Sticker> combi) {

    if (combi[0].w + combi[1].w <= W){
        if(max(combi[0].h, combi[1].h) <= H) return true;
    }

    if (combi[0].h + combi[1].h <= H) {
        if (max(combi[0].w, combi[1].w) <= W) return true;
    }

    return false;
}

int main() {
    int answer = 0;
    cin>>H>>W>>N;

    for (int i = 0; i <N; ++i) {
        int height, width;
        cin>>width>>height;

        stickers.push_back(Sticker(width, height, i));
        if (width!=height) stickers.push_back(Sticker(height, width, i));
    }

    vector<vector<Sticker>> combinations = makeCombi();

    for (int i = 0; i < combinations.size(); ++i) {
        if (possible(combinations[i])){
            Sticker a = combinations[i][0], b = combinations[i][1];
            int size = a.w*a.h + b.w*b.h;
            answer = max(answer, size);
        }
    }

    cout<<answer<<'\n';

    return 0;
}
