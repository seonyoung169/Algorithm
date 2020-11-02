//프로그래머스 정렬 #1 k번째 수, 성공

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int i,j,k;
    for(int h=0; h<commands.size(); h++){
        i = commands[h][0];
        j = commands[h][1];
        k = commands[h][2];
        
        vector<int> subarray; //부분 배열 추출
        for(int m=i; m<=j; m++){
            subarray.push_back(array[m-1]);
        }
        
        sort(subarray.begin(), subarray.end());
        answer.push_back(subarray[k-1]);
    }
    return answer;
}
