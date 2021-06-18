#include <vector>
#include <algorithm>

using namespace std;

int getConnectedNumber(int N, int times){
    int ans = 0;

    for (int i = 0; i < times-1; ++i) {
        ans *= 10;
        ans += (N * 10);
    }
    ans += N;

    return ans;
}

bool basicOperating(vector<vector<int>> & sets, int a, int b, int number){
    int n = a+b;

    for (int i = 0; i < sets[a].size(); ++i) {
        for (int j = 0; j < sets[b].size(); ++j) {
            int subtract, divide, sum, multiple;
            subtract = sets[a][i] - sets[b][j];
            divide = sets[a][i] / sets[b][j];

            if (subtract >= 1) sets[n].push_back(subtract);
            if (divide >= 1) sets[n].push_back(divide);

            if (a >= b) {
                sum = sets[a][i] + sets[b][j];
                multiple = sets[a][i] * sets[b][j];

                sets[n].push_back(sum);
                sets[n].push_back(multiple);
            }

            if (subtract == number || divide == number || sum == number || multiple == number) return true;

        }
    }

    return false;
}

int solution(int N, int number) {
    int answer = 0;
    bool found = false;
    vector<vector<int>> numsUsingN(9);

    vector<int> base = {N, N*10 + N, N+N, N*N, N/N};

    if (base[0] == number) return 1;
    numsUsingN[1].push_back(N);

    for (int i = 1; i < base.size() ; ++i) {
        if (base[i] == number) return 2;
        numsUsingN[2].push_back(base[i]);
    }

    numsUsingN[2].erase(unique(numsUsingN[2].begin(), numsUsingN[2].end()), numsUsingN[2].end());

    for (int i = 3; i <= 8 ; ++i) {
        int connected = getConnectedNumber(N, i);

        if (connected == number) {
            found = true;
            break;
        }else{
            numsUsingN[i].push_back(connected);
        }

        for (int j = i-1; j >= 1 ; j--) {
            if (basicOperating(numsUsingN, j, i-j, number)){
                answer = i;
                found = true;
                break;
            }
        }

        if (found) break;
    }

    if (!found) answer = -1;

    return answer;
}
