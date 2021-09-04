#include <iostream>
#include <string>
#include <vector>

// 프로그래머스 키패드 누르기, Level 1 
using namespace std;

int getDistance(pair<int, int> from, pair<int, int> to){
    return (abs(from.first-to.first) + abs(from.second - to.second));
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> lthumb = make_pair(3,0);
    pair<int, int> rthumb = make_pair(3,2);

    vector<pair<int, int>> point(10);
    point[0] = make_pair(3,1);
    point[1] = make_pair(0,0);
    point[2] = make_pair(0,1);
    point[3] = make_pair(0,2);
    point[4] = make_pair(1,0);
    point[5] = make_pair(1,1);
    point[6] = make_pair(1,2);
    point[7] = make_pair(2,0);
    point[8] = make_pair(2,1);
    point[9] = make_pair(2,2);

    for (int i = 0; i < numbers.size(); ++i) {
        int time = numbers[i]/3;
        int left = numbers[i] % 3;

        if (left == 1) {
            answer += "L";
            lthumb = point[numbers[i]];
        }
        else if (numbers[i] > 0 && left == 0){
            answer += "R";
            rthumb = point[numbers[i]];
        }
        else { // 2,5,8,0
            int useL = getDistance(lthumb, point[numbers[i]]);
            int useR = getDistance(rthumb, point[numbers[i]]);

            if (useL == useR){
                if (hand == "left"){
                    answer += "L";
                    lthumb = point[numbers[i]];
                } else{
                    answer += "R";
                    rthumb = point[numbers[i]];
                }
            }else{
                if (useL < useR){
                    answer += "L";
                    lthumb = point[numbers[i]];
                }else{
                    answer += "R";
                    rthumb = point[numbers[i]];
                }
            }
        }
    }

    return answer;
}
