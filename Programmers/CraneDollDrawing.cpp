#include <vector>
#include <stack>

// 프로그래머스 크레인 인형뽑기 게임, 2019 카카오 개발자 겨울 인턴십, level 2
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();

    stack<int> basket;
    vector<stack<int>> tower(n);

    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            if(board[i][j]>0){
                tower[j].push(board[i][j]);
            }
        }
    }

    for(int i=0; i<moves.size(); i++){
        if(tower[moves[i]-1].empty()) continue;
        if(basket.empty()){
            basket.push(tower[moves[i]-1].top());
        }else{
            if(tower[moves[i]-1].top() == basket.top()){
                answer++;
                basket.pop();
            }else {
                basket.push(tower[moves[i] - 1].top());
            }
        }
        tower[moves[i]-1].pop();
    }

    return 2*answer;
}
