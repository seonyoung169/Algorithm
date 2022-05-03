#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <cmath>

// 프로그래머스 주차 요금 계산, level 2, 구현 
using namespace std;

int baseTime, baseFee, unitTime, unitFee;

struct Info {
    int charge = 0;
    int totalstay = 0;
    int in = -1;
    int out = -1;
};

bool cmp (pair<string,Info> a, pair<string,Info> b){
    return a.first<b.first;
};

vector<string> split(string str){
    vector<string> result;
    stringstream ss(str);
    string token;

    while (getline(ss, token, ' ')) {
        result.push_back(token);
    }

    return result;
}

int convert(string str){
    return stoi(str.substr(0,2)) * 60 + stoi(str.substr(3,2));
}

int calculate(int stay){
    int result = baseFee;

    if(stay > baseTime){
        stay -= baseTime;
        int count = stay / unitTime, left = stay % unitTime;
        result += count * unitFee;
        if (left > 0) result += unitFee;
    }

    return result;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, Info> payment;

    baseTime = fees[0], baseFee = fees[1], unitTime = fees[2], unitFee = fees[3];

    for (int i = 0; i < records.size(); ++i) {
        vector<string> tokens = split(records[i]);
        int time = convert(tokens[0]);

        if(tokens[2] == "IN") {  // 입차
            if (payment.find(tokens[1]) == payment.end()) payment.insert({tokens[1], Info()});
            payment[tokens[1]].in = time;
        } else{  //출차
            payment[tokens[1]].out = time;
            payment[tokens[1]].totalstay += payment[tokens[1]].out - payment[tokens[1]].in;
            payment[tokens[1]].in = -1;
            payment[tokens[1]].out = -1;
        }
    }

    vector<pair<string, Info>> temp;
    for (auto iter = payment.begin(); iter!=payment.end(); iter++){
        if(iter->second.in != -1 && iter->second.out == -1){
            iter->second.totalstay += (23*60 + 59) - iter->second.in;
        }
        iter->second.charge = calculate(iter->second.totalstay);
        temp.push_back(*iter);
    }
    sort(temp.begin(), temp.end(), cmp);

    // 결과 옮기기
    for (int i = 0; i < temp.size(); ++i) {
        answer.push_back(temp[i].second.charge);
    }

    return answer;
}
