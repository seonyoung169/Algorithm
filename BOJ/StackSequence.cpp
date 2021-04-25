#include <iostream>
#include <stack>
#include <vector>

//BOJ 1874 스택 수열, 스택 이용 
using namespace std;

bool isAble = false;

int main() {
    int N;
    cin>>N;

    stack<int> stack;
    vector<int> sequence(N,0);
    vector<char> operation;

    int flag = 0, number=1;
    for (int i=0; i <N; ++i) {
        cin>>sequence[i];
    }

    while (!isAble){
        if (stack.empty()){
            stack.push(number);
            operation.push_back('+');
            number++;
        }

        if (sequence[flag] == stack.top()){
            stack.pop();
            operation.push_back('-');
            flag++;
        }else{
            if (number <=N){
                stack.push(number);
                operation.push_back('+');
                number++;
            }else{
                break;
            }
        }

        if (flag >= N && number > N) {
            isAble = true;
            break;
        }
    }

    if (isAble){
        for (int i = 0; i < operation.size(); ++i) {
            cout<<operation[i]<<'\n';
        }
    }else{
        cout<<"NO"<<'\n';
    }

    return 0;
}
