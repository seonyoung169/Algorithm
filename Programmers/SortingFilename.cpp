#include <string>
#include <vector>
#include <algorithm>

// 프로그래머스 파일명 정렬, level 2, 문자열
using namespace std;

struct file {
    string head;
    int number;
    int idx;

    file(string h, int n, int i) : head(h), number(n), idx(i) {}
};

bool cmp (file a, file b){
    if (a.head == b.head){
        if(a.number == b.number){
            return a.idx < b.idx;
        }
        return a.number < b.number;
    }

    return a.head < b.head;
};


vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<file> nameinfo;

    for (int i = 0; i < files.size(); ++i) {
        string head = "", number = "";
        int j;
        for (j = 0; j < files[i].size(); ++j) {
            if(files[i][j] >= '0' && files[i][j]<='9') break;
            head += files[i].substr(j,1);
        }

        while (j<files[i].size()){
            if (files[i][j] < '0' || files[i][j] > '9') break;
            number += files[i].substr(j++,1);
        }

        transform(head.begin(), head.end(), head.begin(), ::tolower);
        nameinfo.push_back(file(head, stoi(number), i));
    }

    sort(nameinfo.begin(), nameinfo.end(), cmp);

    for (int i = 0; i < nameinfo.size(); ++i) answer.push_back(files[nameinfo[i].idx]);

    return answer;
}
