#include <string>
#include <vector>

//프로그래머스 스택/큐 - 기능개발 맞았음!
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> left, timeline;

    for(int i=0; i<progresses.size(); i++){
        int leftwork = 100-progresses[i];
        left.push_back(leftwork);

        int worktime = leftwork/speeds[i];
        if(leftwork%speeds[i] > 0){
            worktime++;
        }
        timeline.push_back(worktime);
    }

    int flag = timeline[0];
    int published = 1;
    for(int i=1; i<timeline.size(); i++){
        if(timeline[i]<=flag){
            published++;
        }else{
            answer.push_back(published);
            flag = timeline[i];
            published = 1;
        }
    }
    answer.push_back(published);
    return answer;
}

int main(){
    vector<int> answer;

    answer = solution({93, 30, 55}, {1, 30, 5});

    return 0;
}
