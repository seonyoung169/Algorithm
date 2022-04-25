#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>

// 프로그래머스 방금그곡, level2, string 
using namespace std;

struct Song {
    string title;
    int running;
    string played;
    int seq;

    Song(string t, int r, string p, int s) : title(t), running(r), played(p), seq(s) {}
};

bool cmp (Song a, Song b){
    if (a.running == b.running) return a.seq < b.seq;
    return a.running > b.running;
};

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

string replaceMelody(string melody){
    string result = melody;

    result = regex_replace(melody, regex("C#"), "c");
    result = regex_replace(result, regex("D#"), "d");
    result = regex_replace(result, regex("F#"), "f");
    result = regex_replace(result, regex("G#"), "g");
    result = regex_replace(result, regex("A#"), "a");

    return result;
}

int convertTime(string time){
    return stoi(time.substr(0,2))*60 + stoi(time.substr(3,2));
}

int getSongLength(string melody){
    int len = 0;
    for (int i = 0; i < melody.size(); ++i) {
        if (melody[i]=='#') continue;
        len++;
    }
    return len;
}

string getPlayedMelody(string origin, int running, int len){
    if (len > running){
        return origin.substr(0,running);
    }

    string result = origin;
    int left = running-len, j=0;

    while (left > 0){
        result += origin.substr(j,1);
        if (origin[j] != '#') left--;
        j = (j+1) % origin.size();
    }

    return result;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    vector<Song> songdata;
    m = replaceMelody(m);

    // musicinfos 정리
    for (int i = 0; i < musicinfos.size(); ++i) {
        vector<string> tokens = split(musicinfos[i], ',');
        tokens[3] = replaceMelody(tokens[3]);

        int running = convertTime(tokens[1]) - convertTime(tokens[0]);
        int len = getSongLength(tokens[3]);

        string played = tokens[3];
        if (len != running){
            played = getPlayedMelody(tokens[3], running, len);
        }

        songdata.push_back(Song(tokens[2], running, played, i));
    }

    // 정렬
    sort(songdata.begin(), songdata.end(), cmp);

    for (int i = 0; i < songdata.size(); ++i) {
        if (songdata[i].played.find(m) != string::npos){
            answer = songdata[i].title;
            break;
        }
    }

    return answer;
}
