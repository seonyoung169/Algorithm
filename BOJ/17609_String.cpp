#include <iostream>
#include <string>
#include <vector>

// boj 17609 회문, 문자열, 실버 1
using namespace std;

vector<int> answer;

int check(string str){
    int start = 0, end = str.size()-1;
    int result = 0;

    while (start<=end){
        if (str[start] == str[end]){
            start++;
            end--;
        }else{
            int left = start+1, right = end;
            bool left_pass = true;
            while (left<=right){
                if(str[left] !=  str[right]){
                    left_pass = false;
                    break;
                }
                left++;
                right--;
            }

            if (left_pass){
                result = 1;
                return result;
            }

            left = start, right = end-1;
            bool right_pass = true;
            while (left<=right){
                if (str[left] != str[right]){
                    right_pass = false;
                    break;
                }
                left++;
                right--;
            }

            if (right_pass) result = 1;
            else result = 2;

            return result;
        }
    }
    return result;
}
int main() {
    int T;
    cin>>T;

    answer.assign(T, -1);
    for (int i = 0; i < T; ++i) {
        string input;
        cin>>input;
        answer[i] = check(input);
    }

    for (int i = 0; i < T; ++i) {
        cout<<answer[i]<<"\n";
    }
    return 0;
}
