#include <iostream>
#include <vector>

// boj 16432 dfs, 골드 5, 이건 실패다,,
using namespace std;

int N;
bool visited[1001][10] = {false};

vector<vector<int>> riceCake;
vector<int> answer;

bool dfs(int before, int day){
    if (day == N){  // 마지막 날에 먹을 떡 고르기!
        for (int i = 0; i < riceCake[day-1].size(); ++i) {
            if (before != riceCake[day-1][i]){
                answer[day-1] = riceCake[day-1][i];
                return true;
            }
        }
    }


    for (int i = 0; i < riceCake[day-1].size(); ++i) {
        int next = riceCake[day-1][i]; // 먹을 떡

        if (before != next && !visited[day+1][next]){  // 이 떡을 먹은 경우를 아직 확인하지 않았다면
            visited[day+1][next] = true;
            answer[day-1] = next;
            if(dfs(next, day+1)){
                return true;
            }
        }
    }

    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    answer.assign(N, 0);

    int count;
    for (int i = 0; i < N; ++i) {
        cin>>count;
        int num;
        vector<int> cakes;
        for (int j = 0; j < count; ++j) {
            cin>>num;
            cakes.push_back(num);
        }
        riceCake.push_back(cakes);
    }

    if (dfs(0, 1)){
        for (int i = 0; i < N; ++i) {
            cout<<answer[i]<<'\n';
        }
    }else{
        cout<<-1;
    }

    return 0;
}
