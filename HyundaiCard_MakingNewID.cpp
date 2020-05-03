#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

string solution(vector<string> registered_list, string new_id);
int idExist(vector<string> registered_list, string new_id);

int main(){
    vector<string> registered_list = { "cow", "cow1", "cow2", "cow3", "cow4", "cow9", "cow8", "cow7", "cow6", "cow5"};
    string new_id = "cow";

    cout<<solution(registered_list, new_id);

    return 0;
}

string solution(vector<string> registered_list, string new_id) {
    string answer = "";

    string S, N, N1;
    int numIdx = 0, numStr;
    while (idExist(registered_list, new_id)) { //registered_list 에 new_id 가 존재 하면
        int i;
        for (i = 0; i < new_id.size(); ++i) {
            if( 48 <= new_id[i] && new_id[i] <= 57) {
                numIdx = i; //N 시작 부분 idx
                break;
            }
        }

        if(i == new_id.size()) numIdx = 3;
        S = new_id.substr(0,numIdx);
        if(numIdx == new_id.size()) {
            numStr = 0;
        }else{
            N = new_id.substr(numIdx, new_id.size()-numIdx);
            numStr = atoi(N.c_str());
        }
        numStr++;
        N1 = to_string(numStr);

        new_id = S+N1;
    }

    answer = new_id;
    return answer;
}

int idExist(vector<string> registered_list, string new_id){
    for(int i=0;i<registered_list.size();i++){
        if(!registered_list[i].compare(new_id)) return 1;
    }
    return 0;
}
