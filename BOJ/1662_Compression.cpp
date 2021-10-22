#include <iostream>
#include <stack>
#include <string>

// boj 1662 압축, 골드 5, 스트링
using namespace std;

int unzipString(string compressed){
    stack<int> st;

    for (int i = 0; i < compressed.size(); ++i) {
        if (i<compressed.size()-1 && compressed[i+1] == '('){
            st.push(compressed[i]-'0');
        }else if (compressed[i]=='('){
            st.push(100);
        }else if (compressed[i]==')'){
            int len = 0;
            while (st.top()!= 100){
                len += st.top();
                st.pop();
            }
            st.pop();
            int count = st.top();
            st.pop();
            st.push(count*len);
        }else{
            st.push(1);
        }
    }

    int answer = 0;
    while (!st.empty()){
        answer += st.top();
        st.pop();
    }

    return answer;
}

int main() {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string compressed;
    cin>>compressed;

    cout<<unzipString(compressed);

    return 0;
}
