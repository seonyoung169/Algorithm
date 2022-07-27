#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// boj 5766 할아버지는 유명해, 실버 4, 구현 
using namespace std;

int main() {
    int N, M;
    cin>>N>>M;

    do {
        map<int, int> score;
        int player, max_score = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin>>player;
                int frag_score = 5-j;

                if (score.find(player) != score.end()){
                    score[player] += 1;
                } else {
                    score.insert({player, 1});
                }

                max_score = max(max_score, score[player]);
            }
        }

        int second_score = 0;
        for(auto iter=score.begin(); iter!=score.end(); iter++){
            if (iter->second<max_score && iter->second>second_score){
                second_score = iter->second;
            }
        }

        vector<int> second_players;
        for(auto iter=score.begin(); iter!=score.end(); iter++) {
            if (iter->second == second_score) second_players.push_back(iter->first);
        }

        if (second_players.size()>1) sort(second_players.begin(), second_players.end());
        for (int i = 0; i < second_players.size(); ++i) cout<<second_players[i]<<' ';
        cout<<'\n';

        cin>>N>>M;
    }while (!(N==0 && M==0));

    return 0;
}
