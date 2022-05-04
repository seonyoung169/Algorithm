#include <string>
#include <vector>

// 프로그래머스 양궁대회, level 2, 완전 탐색, 어려운 구현 
using namespace std;

int maxDiff = 0;
vector<int> answer;

bool check(vector<int> temp){
    for (int i = 10; i >= 0 ; --i) {
        if (temp[i]>answer[i]) return true;
        else if (temp[i]<answer[i]) return false;
    }
}

void calculate(vector<int> ryan, vector<int> apeach){  // 점수 계산
    int score_ryan = 0, score_apeach = 0;

    for (int i = 0; i < 11; ++i) {
        if (ryan[i] ==0 && apeach[i]==0) continue;
        if (ryan[i] > apeach[i]) score_ryan += 10-i;
        else score_apeach += 10-i;
    }

    int diff = score_ryan - score_apeach;

    if (diff>0 && maxDiff <= diff){
        if (maxDiff==diff && !check(ryan)) return;
        maxDiff = diff;
        answer = ryan;
    }

}

void search(vector<int> & ryan, vector<int> & apeach, int idx, int leftarrow){
    if (idx==11 || leftarrow == 0) {
        ryan[10] += leftarrow;
        calculate(ryan, apeach);
        ryan[10] -= leftarrow;
        return;
    }

    if (apeach[idx] < leftarrow){
        ryan[idx] += apeach[idx]+1;
        search(ryan, apeach, idx+1, leftarrow-ryan[idx]);
        ryan[idx] -= apeach[idx]+1;
    }

    search(ryan, apeach, idx+1, leftarrow);

}
vector<int> solution(int n, vector<int> info) {
    answer = {-1};

    vector<int> ryan(11,0);
    search(ryan, info, 0, n);

    return answer;
}
