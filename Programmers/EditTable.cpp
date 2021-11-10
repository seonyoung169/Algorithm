#include <iostream>
#include <vector>
#include <set>
#include <stack>

// 프로그래머스 표 편집, level 3
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');
    set<int> table;
    stack<int> deleted;

    for (int i = 0; i < n; ++i) table.insert(i);

    auto iter = table.find(k);

    for (int i = 0; i < cmd.size(); ++i) {
        char command = cmd[i][0];

        if (command=='D'){
            int down = stoi(cmd[i].substr(2,cmd[i].size()-2));
            while (down>0){
                iter = next(iter);
                down--;
            }

        }else if (command=='U'){
            int up = stoi(cmd[i].substr(2,cmd[i].size()-2));
            while (up>0){
                iter = prev(iter);
                up--;
            }
        }else if (command=='C'){
            deleted.push(*iter);
            iter = table.erase(iter);
            if (iter==table.end()) iter = prev(iter);
        }else{
            table.insert(deleted.top());
            deleted.pop();
        }
    }

    for(int i : table) answer[i] = 'O';

    return answer;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string answer = solution(8,2,{"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"});

    cout<<answer;

   return 0;
}
