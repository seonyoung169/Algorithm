//Programmers_완전탐색_모의고사, 맞음

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int, int>> count;
    for(int i=0; i<3; i++){
        count.push_back(make_pair(0, i+1));
    }

    vector<int> secondpattern = {2,1,2,3,2,4,2,5};
    vector<int> thirdpattern = {3,3,1,1,2,2,4,4,5,5};

    for(int i=0; i<answers.size(); i++){
        int ans = answers[i];

        //1번 수포자 i번 문제 답 = i%5
        if(ans == i%5 +1){
            count[0].first += 1;
        }

        //2번 수포자 i번 문제 답 = 8개주기
        int left2 = i % 8;
        if(ans == secondpattern[left2]){
            count[1].first += 1;
        }

        //3번 수포자
        int left3 = i%10;
        if(ans == thirdpattern[left3]){
            count[2].first += 1;
        }
    }

    sort(count.begin(), count.end());

    answer.push_back(count[2].second);
    for(int i=1; i>=0; i--){
        if(count[i].first == count[2].first){
            answer.push_back(count[i].second);
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}
