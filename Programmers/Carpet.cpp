#include <vector>
#include <cmath>

// 프로그래머스 완전탐색 - 카펫, 맞음!

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int blocks = brown + yellow;
    int root = sqrt(blocks);
    int yellowWidth = 1, yellowHeight=1;

    while (yellowWidth+2<=root){
        if(blocks%(yellowWidth+2)==0){
            yellowHeight = blocks / (yellowWidth+2) - 2;
            if(yellowWidth*yellowHeight == yellow){
                break;
            }
        }
        yellowWidth++;
    }

    answer.push_back(yellowHeight+2);
    answer.push_back(yellowWidth+2);

    return answer;
}
