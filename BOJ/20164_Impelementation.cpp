#include <iostream>
#include <string>
#include <limits.h>
#include <vector>
#include <algorithm>

// boj 20164 홀수 홀릭 호석, 골드 5, 구현
using namespace std;

int MAX = -1;
int MIN = INT_MAX;

vector<vector<int>> makeIndexes(int len){
    vector<vector<int>> result;

    vector<bool> select(len-2, false);
    for (int i = 0; i < 2; ++i) select.push_back(true);

    do{
        vector<int> combi;
        for (int i = 0; i < len; ++i) {
            if (select[i]) combi.push_back(i+1);
        }
        result.push_back(combi);
    }while (next_permutation(select.begin(), select.end()));

    return result;
}

void solution(string N, int count){
    if (N.size() == 1){
        if ((N[0]-'0')%2 == 1) count++;
        if (MIN > count) MIN = count;
        if (MAX < count) MAX = count;
        return;
    }

    if (N.size() == 2){
        char front = N[0], back = N[1];

        if ((front -'0') % 2 == 1) count++;
        if ((back -'0') % 2 == 1) count++;

        int sum = stoi(N.substr(0,1)) + stoi(N.substr(1,1));
        solution(to_string(sum), count);
        return;
    }

    int len = N.size();
    for (int i = 0; i < len ; ++i) {
        if ((N[i]-'0')%2 == 1) count++;
    }
    vector<vector<int>> index_combination = makeIndexes(len-1);
    for (int i = 0; i < index_combination.size(); ++i) {
        int first = stoi(N.substr(0,index_combination[i][0]));
        int mid = stoi(N.substr(index_combination[i][0], index_combination[i][1]-index_combination[i][0]));
        int last = stoi(N.substr(index_combination[i][1], len-index_combination[i][1]));
        string str_sum = to_string(first+mid+last);
        solution(str_sum, count);
    }
}


int main() {
    string N;
    cin>>N;

    solution(N, 0);

    cout<<MIN<<" "<<MAX;

    return 0;
}
