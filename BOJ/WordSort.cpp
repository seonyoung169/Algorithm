#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//BOJ 1181 단어 정렬 문제 - STL sort compare 함수 이용해보기
using namespace std;

bool compare(string a, string b){
    if( a.length() < b.length()){
        return 1;
    } else if (a.length() > b.length()){
        return 0;
    }else{
        return a < b;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    string str;
    vector<string> words;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>str;
        words.push_back(str);
    }

    sort(words.begin(), words.end(), compare);

    cout<<words.at(0)<<'\n';
    for(int i=1 ;i<N; i++){
        if(words.at(i-1) != words.at(i)){
            cout<<words.at(i)<<'\n';
        }
    }

    return 0;
}
