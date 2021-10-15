#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

//boj 20291 파일 정리, string, 실버 4
using namespace std;

void cleanFile(vector<string> files){

    map<string, int> count;
    vector<string> keyList;

    for (int i = 0; i < files.size(); ++i) {
        for (int j = 0; j < files[i].size(); ++j) {
            if (files[i][j]=='.'){
                string key = files[i].substr(j+1, files[i].size()-j+1);

                if (count.find(key) == count.end()) {
                    count[key] = 1;
                    keyList.push_back(key);
                }
                else count[key] += 1;
            }
        }
    }

    sort(keyList.begin(), keyList.end());

    for (int i = 0; i < keyList.size(); ++i) {
        cout<<keyList[i]<<" "<<count[keyList[i]]<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>>N;
    vector<string> files(N);

    for (int i = 0; i < N; ++i) cin>>files[i];

    cleanFile(files);

    return 0;
}
