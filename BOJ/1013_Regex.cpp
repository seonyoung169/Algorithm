#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {

    int T;
    cin>>T;

    regex re("(100+1+|01)+");

    for (int i = 0; i < T; ++i) {
        string input;
        cin>>input;

        if(regex_match(input, re)==1) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }

    return 0;
}
