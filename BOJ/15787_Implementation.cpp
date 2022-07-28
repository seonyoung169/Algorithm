#include <iostream>
#include <vector>
#include <set>
#include <string>

// boj 15787 기차가 어둠을 헤치고 은하수를, 실버 2 
using namespace std;

vector<string> trains;

void operate(int command, int idx, int seat) {
    switch (command) {
        case 1:
            trains[idx][seat-1] = '1';
            break;
        case 2:
            trains[idx][seat-1] = '0';
            break;
        case 3:
            trains[idx] = "0"+ trains[idx].substr(0, 19);
            break;
        case  4:
            trains[idx] = trains[idx].substr(1,19) + "0";
            break;
    }
}

int main() {
    int N, M;
    cin>>N>>M;

    string base = "";
    for (int i = 0; i < 20; ++i) base += "0";

    trains.resize(N+1, base);

    for (int i = 0; i < M; ++i) {
        int command, idx, seat;
        cin>>command>>idx;
        if (command <=2) cin>>seat;
        operate(command, idx, seat);
    }

    set<string> passed;
    for (int i = 1; i <= N; ++i) {
        if (passed.find(trains[i]) != passed.end()) continue;
        passed.insert(trains[i]);
    }

    cout<<passed.size();

    return 0;
}
