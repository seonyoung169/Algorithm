#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<string> kinds = gems;

    sort(kinds.begin(), kinds.end());
    kinds.erase(unique(kinds.begin(), kinds.end()), kinds.end());

    if (kinds.size()==1){
        answer.push_back(1);
        answer.push_back(1);
        return answer;
    }


    int left = 0, right = 0, length = gems.size()+1;
    int start = 0, end = 0 ;

    map<string, int> count;
    count[gems[0]] = 1;


    while (left<=right && left>=0 && left<gems.size() && right>=0 && right<gems.size()){
        if (count.size() == kinds.size()){
            if (length > right-left+1){
                length = right-left+1;
                start = left;
                end = right;
            }

            if (count[gems[left]] == 1) count.erase(gems[left]);
            else count[gems[left]] -= 1;
            left++;
        }else{
            if (right +1 <gems.size()){
                if (count.find(gems[right+1]) == count.end()) count[gems[right+1]] = 1;
                else count[gems[right+1]] += 1;
            }
            right++;
        }
    }


    answer.push_back(start+1);
    answer.push_back(end+1);

    return answer;
}
