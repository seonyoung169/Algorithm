#include <vector>
#include <set>

// 프로그래머스 기둥과 보 설치, level 3, 2020 kakao blind recruitment
using namespace std;

set<vector<int>> buildings;

bool isSafe(){
    
    for (auto frag : buildings) {
        if (frag[2]==0){
            if (frag[1]==0) continue;
            if (buildings.find({frag[0], frag[1], 1}) != buildings.end() || buildings.find({frag[0]-1, frag[1], 1}) != buildings.end()) continue;
            if (buildings.find({frag[0], frag[1]-1, 0}) != buildings.end()) continue;
            return false;
        }else{
            if (buildings.find({frag[0], frag[1]-1, 0}) != buildings.end() || buildings.find({frag[0]+1, frag[1]-1, 0}) != buildings.end()) continue;
            if (buildings.find({frag[0]-1, frag[1], 1}) != buildings.end() && buildings.find({frag[0]+1, frag[1], 1}) != buildings.end()) continue;
            return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for(int i=0; i<build_frame.size(); i++){
        vector<int> fragment = {build_frame[i][0],build_frame[i][1], build_frame[i][2]};

        if (build_frame[i][3] == 1){
            buildings.insert(fragment);
            if (!isSafe()){
                buildings.erase(fragment);
            }
        }else{
            buildings.erase(fragment);
            if (!isSafe()){
                buildings.insert(fragment);
            }
        }
    }

    for (auto frag : buildings){
        answer.push_back(frag);
    }

    return answer;
}
