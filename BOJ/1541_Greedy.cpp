#include <iostream>
#include <vector>
#include <string>
#include <stack>

// boj 1541 잃어버린 괄호, greedy, 실버 2
using namespace std;

int makeMinResult(string input){
    vector<string> token;

    // 연산 식 잘라서 배열에 담기 
    int from = 0;
    for (int i = 1; i < input.size(); ++i) {
        if (input[i]=='+'|| input[i]=='-'){
            int num = stoi(input.substr(from, i-from));
            token.push_back(to_string(num));
            token.push_back(input.substr(i, 1));
            i++;
            from = i;
        }
    }
    int num = stoi(input.substr(from, input.size()-from));
    token.push_back(to_string(num));

    int at = 0, answer =0;

    while (at<token.size()){
        if (token[at]=="+") at++;  // + 부호는 넘어가고 

        else if (token[at]=="-"){ // -부호가 등장하면 다음 - 까지 모두 더해서 결과값에서 빼주기 
            at++;
            int sum = 0;

            while (at<token.size() && token[at] != "-"){
                if (token[at] == "+") at++;
                else sum += stoi(token[at++]);
            }
            answer -= sum;
        }else answer += stoi(token[at++]);  // - 연산에 걸리지 않는 수는 더해주기 
    }
    return answer;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin>>input;

    cout<<makeMinResult(input);

  }
