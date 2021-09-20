#include <string>
#include <vector>
#include <algorithm>

// 프로그래머스 셔틀버스, 2018 kakao blind recruitment, level3, simulation
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> crews;

    for(int i=0; i<timetable.size(); i++){
        int minute = stoi(timetable[i].substr(0,2)) * 60 + stoi(timetable[i].substr(3,4));
        crews.push_back(minute);
    }
    sort(crews.begin(), crews.end());

    int shuttle = 540;
    int index = 0;
    int corn_time = 0;

    for (int i = 1; i <= n ; ++i, shuttle += t) {
        int ride = 0;
        for (int j = index; j < crews.size(); ++j) {
            if (crews[j] > shuttle) break;
            if (crews[j] <= shuttle) {
                ride++;
                index++;
                if (ride == m) break;
            }
        }

        if (i==n){
            if (ride == m) corn_time = crews[index-1]-1;
            else corn_time = shuttle;
        }
    }

    if (corn_time/60 < 10) answer += "0";
    answer += to_string(corn_time/60) + ":";

    if (corn_time%60 < 10) answer += "0";
    answer += to_string(corn_time%60);


    return answer;
}
