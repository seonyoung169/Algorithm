#include <iostream>
#include<string>
#include <stack>

// 프로그래머스 짝지어 제거하기, level 2, 스택 사용 
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> st;
    st.push(s[0]);
    
    for(int i=1; i<s.size(); i++){
        if(st.empty()) {
            st.push(s[i]);
            continue;
        }
    
        if(st.top()==s[i]){
            st.pop();
        }else{
            st.push(s[i]);
        }
    }

    if(st.empty()) answer = 1;
    else answer = 0;
    
    return answer;
}
