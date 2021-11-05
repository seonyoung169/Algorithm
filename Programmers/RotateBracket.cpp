#include <string>
#include <stack>

// 프로그래머스 괄호 회전하기 level 2
using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.size(), rotate = 0;
    
    if(len%2 == 1) return 0;
    
    do{
        stack<string> st;
        bool correct = true;
        
        for(int i=0; i<s.size(); i++){
            string tok = s.substr(i,1);
            if(tok== "{" || tok== "(" || tok== "[") st.push(tok);
            else{
                if(st.empty()) {
                    correct = false;
                    break;
                }
                
                if((tok=="}"&&st.top()=="{") || (tok=="]"&&st.top()=="[") || (tok==")"&&st.top()=="(")){
                    st.pop();
                }else {
                    correct = false;
                    break;
                }
            }
        }
        
        if(correct) answer++;
        s = s.substr(1, len-1) + s.substr(0,1);
        rotate++;
        
    }while(rotate<len);
    
    
    return answer;
}
