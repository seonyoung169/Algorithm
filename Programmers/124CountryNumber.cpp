#include <string>
#include <vector>

using namespace std;


string solution(int n) {
    string answer = "";

    int share = n;
    int left= -2;

    while(share > 0){
        left = share%3;
        share = share/3;

        if(left == 0){
            answer = "4" + answer;
            share--;
        }else if (left == 1){
            answer = "1" + answer;
        }else{
            answer = "2" + answer;
        }

    }

    return answer;
}
