#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

// 프로그래머스 단체 사진 찍기, level2, 순열 + dfs..?
using namespace std;

struct rule {
    string fa, fb, op;
    int demand;
    rule(string a, string b, string o, int d){
        fa = a;
        fb = b;
        op = o;
        demand = d;
    }
};

int answer;
int cnt;
vector<string> friends;
vector<rule> rule_list;
vector<bool> visited;

bool checkCondition(string line){
    for (int i = 0; i < rule_list.size(); ++i) {
        int loc_a = line.find(rule_list[i].fa);
        int loc_b = line.find(rule_list[i].fb);
        int distance = abs(loc_a-loc_b)-1;
        int demand = rule_list[i].demand;

        if (rule_list[i].op == "=" && !(distance==demand)) return false;
        else if (rule_list[i].op == "<" && !(distance<demand)) return false;
        else if (rule_list[i].op == ">" && !(distance>demand)) return false;
    }
    return true;
}

void makeLine(string line){
    if (line.size() == 8){
        cnt++;
        if (checkCondition(line)) answer++;
        return;
    }

    for (int i = 0; i < 8; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        makeLine(line+friends[i]);
        visited[i] = false;
    }
}

int solution(int n, vector<string> data) {
    answer = 0, cnt = 0;
    friends = {"A", "C", "F", "J", "M", "N", "R", "T"};
    visited.resize(8, false);
    rule_list.clear();

    for (int i = 0; i <n; ++i) {
        string fa = data[i].substr(0,1);
        string fb = data[i].substr(2,1);
        string op = data[i].substr(3,1);
        int demand = stoi(data[i].substr(4,1));
        rule_list.push_back(rule(fa, fb, op, demand));
    }

    vector<bool> visited(8, false);
    makeLine("");

    return answer;
}
