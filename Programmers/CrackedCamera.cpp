#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 프로그래머스 Greedy - 단속카메라
using namespace std;

bool byExit(vector<int> route1, vector<int> route2) {
    return route1[1] < route2[1];
}

int solution(vector<vector<int>> routes) {
    int cameraAt = -30001;

    vector<int> cameraLocation;
    vector<vector<int>> routeByExit;

    sort(routes.begin(), routes.end(), byExit);
    routeByExit = routes;


    for (int i = 0; i < routeByExit.size() ; ++i) {
        if (routeByExit[i][0] > cameraAt){
            cameraAt = routeByExit[i][1];
            cameraLocation.push_back(cameraAt);
        }else{
            continue;
        }
    }

    return cameraLocation.size();
}

int main() {
    int sol;

//    sol = solution({{-20,15}, {-14,-5}, {-18,-13}, {-5,-3}});
//    sol = solution({{-30,-15}, {-25,-10}, {-15,-12}, {-9,3}, {-2,7}, {10,20}});
    sol = solution({{0,2}, {2,5},{5,7}, {7,12}});

    cout<<sol;

    return 0;
}
