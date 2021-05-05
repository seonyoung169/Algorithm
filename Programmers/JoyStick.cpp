#include <iostream>
#include <string>

//프로그래머스 greedy - 조이스틱, level 2
using namespace std;

int getMoveForward(string name, int start){
    bool exist = false;
    int move = 0, idx = start;
    int len = name.size();

    while (move < len){
        if (name[idx] != 'A'){
            exist = true;
            break;
        }else{
            idx = (idx+1) % len;
            move++;
        }
    }

    if(!exist) move = 21;
    return move;
}

int getMoveBackward(string name, int start){
    bool exist = false;
    int move = 0, idx = start;
    int len = name.size();

    while (move < len){
        if (name[idx] != 'A'){
            exist = true;
            break;
        }else{
            idx = (idx+len-1) % len;
            move++;
        }
    }

    if(!exist) move = 21;
    return move;
}

int getCost(char from){
    int cost = 0;

    if (from <= 78){
        cost = from - 'A';
    }else{
        cost = 'Z' - from + 1;
    }

    return cost;
}

int solution(string name) {
    bool confirmed = false;
    int answer = 0;
    int at = 0, len = name.size();

    while (!confirmed){
        int cost = getCost(name[at]);
        answer += cost;
        name[at] = 'A';

        int forward = getMoveForward(name, at);
        int backward = getMoveBackward(name, at);

        if (forward != 21 && backward != 21){
            if (forward <= backward){
                answer += forward;
                at += forward;
            }else{
                answer += backward;
                at = (at+len-backward) % len;
            }
        }else{
            confirmed = true;
        }
    }

    return answer;
}
