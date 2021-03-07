#include <string>
#include <vector>

// 프로그래머스 스택/큐 - 다리를 지나는 트럭, 맞음!

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int arrived = 0, loaded = 0, trucks = truck_weights.size();
    vector<pair<int, int>> bridge; // 현재 다리 위 트럭들

    while(arrived < trucks){
        answer++;
        //나갈 트럭이 있으면 빼주기
        if(!bridge.empty()){
            if(bridge[0].second == bridge_length){
                loaded -= bridge[0].first;
                bridge.erase(bridge.begin());
                arrived++;
            }
            // 트럭들 한칸 씩 진행
            for(int i=0;i<bridge.size();i++){
                bridge[i].second += 1;
            }
            //맨 뒤칸이 비어 있으면
            if(bridge.empty() || bridge.back().second > 1){
                //더 들어올 수 있으면 새로운 트럭 입장
                if(!truck_weights.empty() &&
                   loaded+truck_weights[0] <= weight){
                    bridge.push_back(make_pair(truck_weights[0], 1));
                    loaded += truck_weights[0];
                    truck_weights.erase(truck_weights.begin());
                }
            }
        }else {
            bridge.push_back(make_pair(truck_weights[0], 1));
            loaded += truck_weights[0];
            truck_weights.erase(truck_weights.begin());
        }
    }

    return answer;
}
