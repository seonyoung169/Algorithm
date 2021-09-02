#include <iostream>
#include <string>
#include <vector>

// 프로그래머스 광고 삽입, level 3, 2021 kakao blind 5번 문제 
using namespace std;

string solution(string play_time, string adv_time, vector<string> logs) {
    long long n = logs.size();
    long long maxTime = 360000;
    long long playTImeSec = 3600*stoi(play_time.substr(0,2)) + 60*stoi(play_time.substr(3,2)) + stoi(play_time.substr(6,2));
    long long advTimeSec = 3600*stoi(adv_time.substr(0,2)) + 60*stoi(adv_time.substr(3,2)) + stoi(adv_time.substr(6,2));

    vector<long long> logsStartSec(n);
    vector<long long> logsEndSec(n);
    vector<long long> videoTime(maxTime, 0);

    // 시작 시간, 종료 시간 변환
    for (long long i = 0; i < n; ++i) {
        long long start = 3600*stoi(logs[i].substr(0,2)) + 60*stoi(logs[i].substr(3,2)) + stoi(logs[i].substr(6,2));
        long long end = 3600*stoi(logs[i].substr(9,2)) + 60*stoi(logs[i].substr(12,2)) + stoi(logs[i].substr(15,2));
        logsStartSec[i] = start;
        logsEndSec[i] = end;
    }

    // 시작 시간, 종료 시간 출입 기록하기
    for (long long i = 0; i < n; ++i) {
        videoTime[logsStartSec[i]] += 1;
        videoTime[logsEndSec[i]] -= 1;
    }

    // i~i+1 에 시청한 시청자 수 구하기
    for (long long i = 1; i < playTImeSec; ++i) {
        videoTime[i] += videoTime[i-1];
    }

    // 0~i 초까지 누적 시청자 수 구하기
    for (long long i = 1; i < playTImeSec; ++i) {
        videoTime[i] += videoTime[i-1];
    }

    long long adStart, adEnd;
    long long total = 0;
    for (long long i = 0; i <= playTImeSec-advTimeSec; ++i) {
        long long s = i, e = i+advTimeSec;
        long long sum  = videoTime[e-1];
        if (s>0){
            sum -= videoTime[s-1];
        }

        if (total < sum){
            adStart = s;
            adEnd = e;
            total = sum;
        }
    }

    // total -> 형식에 맞게 변환
    long long h = adStart/3600;
    adStart = adStart%3600;

    long long m = adStart/60;
    adStart = adStart%60;

    long long s = adStart;

    string answer = "";
    if (h<10){
        answer += "0";
    }
    answer += to_string(h);
    answer += ":";

    if (m<10){
        answer += "0";
    }

    answer += to_string(m);
    answer += ":";

    if (s<10){
        answer += "0";
    }
    answer += to_string(s);

    return answer;
}
