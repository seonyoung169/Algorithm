#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

// boj 1764 듣보잡, string, 자료구조, 실버4
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string name;
    cin>>N>>M;

    set<string> never_listen;
    vector<string> answer;

    for (int i = 0; i < N; ++i){
        cin>>name;
        never_listen.insert(name);
    }

    for (int i = 0; i < M; ++i) {
        cin>>name;
        if (never_listen.find(name) != never_listen.end()) answer.push_back(name);
    }
    sort(answer.begin(), answer.end());
    
    cout<<answer.size()<<'\n';
    for (int i = 0; i < answer.size(); ++i) cout<<answer[i]<<'\n';


   return 0;
}
