#include <string>
#include <vector>
#include <map>

// 프로그래머스 다단계 칫솔 판매, level 3
using namespace std;

typedef struct Info {
    string parent;
    int money;

    Info() {};
    Info(string p, int m) : parent(p), money(m) {};
};

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, Info> organization;
    organization.insert({"center", Info("-", 0)});

    for (int i = 0; i < enroll.size(); ++i) {
        string p = "";
        if (referral[i] == "-") p = "center";
        else  p = referral[i];

        organization.insert({enroll[i],Info(p,0)});
    }

    for (int i = 0; i < seller.size(); ++i) {
        string leaf = seller[i], parent = organization[leaf].parent;
        int profit = amount[i] * 100;

        while (parent!="-"){
            int slice = profit*0.1;
            if (slice<1) break;

            profit -= slice;
            organization[leaf].money += profit;
            leaf = parent;
            parent = organization[leaf].parent;
            profit = slice;
        }
        organization[leaf].money += profit;
    }

    for (int i = 0; i < enroll.size(); ++i) {
        answer.push_back(organization[enroll[i]].money);
    }

    return answer;
}
