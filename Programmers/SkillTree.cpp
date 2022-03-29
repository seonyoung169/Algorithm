#include <string>
#include <vector>
#include <map>

// 프로그래머스 스킬 트리, level2
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> skill_order;

    for (int i = 0; i < skill.size(); ++i) {
        skill_order.insert({skill[i], i});
    }

    for (int i = 0; i < skill_trees.size(); ++i) {
        int cur = 0;
        bool able = true;
        for (int j = 0; j < skill_trees[i].size(); ++j) {
            if (skill_order.find(skill_trees[i][j]) == skill_order.end()) continue;
            if (skill_order[skill_trees[i][j]] == cur){
                cur++;
            }else{
                able = false;
                break;
            }
        }

        if (able) answer++;
    }


    return answer;
}
int main() {

    int ans;
    ans = solution("CBD",{"BACDE", "CBADF", "AECB", "BDA"});


    return 0;
}
