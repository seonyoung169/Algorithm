#include <string>
#include <vector>

// 프로그래머스 순위, level 3, 플로이드 와샬 이용
using namespace std;

vector<vector<int>> match;
vector<int> written;

void writeMatch(int win, int lose){
    if(match[win][lose] == 0 && match[lose][win] == 0){
        match[win][lose] = 1;
        written[win] += 1;

        match[lose][win] = -1;
        written[lose] += 1;

        for (int i = 1; i < match.size(); ++i) {
            if ( i != lose && match[lose][i] == 1){
                writeMatch(win, i);
            }

            if (i != win && match[win][i] == -1){
                writeMatch(i, lose);
            }
        }
    }
    
    return;
}


int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    match.assign(n+1, vector<int>(n+1, 0));
    written.assign(n+1, 0);

    for(int i=0; i<results.size(); i++){
        writeMatch(results[i][0], results[i][1]);
    }

    for(int i=1; i<=n; i++){
        if(written[i] == n-1) answer++;
    }

    return answer;
}
