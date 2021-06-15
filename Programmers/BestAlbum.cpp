#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
 
// 프로그래머스 해시 베스트앨범, level 3
using namespace std;

bool genreByPlay(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}

bool songByPlay(pair<int, int> p1, pair<int, int> p2){
    if (p1.second == p2.second){
        return p1.first<p2.first;
    }
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> playSum;
    vector<pair<string, int>> genresByPlay;
    map<string, vector<pair<int, int>>> songsInGenres;

    // 장르별 합 계산
    for (int i = 0; i < genres.size(); ++i) {
        playSum[genres[i]] += plays[i];
    }

    // 장르별 재생 수 기준으로 내림 차순
    for (auto iter : playSum) {
        genresByPlay.push_back(make_pair(iter.first, iter.second));
    }
    sort(genresByPlay.begin(), genresByPlay.end(), genreByPlay);

    // 장르별로 곡 고유 번호 - 곡 재생수로 해시 생성
    for (int i = 0; i < genres.size() ; ++i) {
        songsInGenres[genres[i]].push_back(make_pair(i,plays[i]));
    }

    for (int i = 0; i < genresByPlay.size(); ++i) {
        string genre = genresByPlay[i].first;
        vector<pair<int, int>> songNumbers = songsInGenres[genre];

        sort(songNumbers.begin(), songNumbers.end(), songByPlay);

        int j = 0;
        while (j<songNumbers.size() && j<2){
            answer.push_back(songNumbers[j].first);
            j++;
        }
    }

    return answer;
}
