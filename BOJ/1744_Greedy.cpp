#include <iostream>
#include <vector>
#include <algorithm>

// boj 1744 수 묶기, 골드 5, 그리디
using namespace std;

vector<int> bigNumbers;
vector<int> smallNumbers;

bool desc(int a, int b) {
    return a>b;
}

int solution(int N) {
    if(N == 1) {
        if(bigNumbers.size() == 1) return bigNumbers[0];
        return smallNumbers[0];
    }

    sort(bigNumbers.begin(), bigNumbers.end(), desc);
    sort(smallNumbers.begin(), smallNumbers.end());

    int sum = 0;
    int i = 0;

    while (i<bigNumbers.size()) {
        if(i==bigNumbers.size()-1) {
            sum += bigNumbers[i];
            break;
        }

        if(bigNumbers[i]+bigNumbers[i+1] <= bigNumbers[i]*bigNumbers[i+1]){
            sum += bigNumbers[i]*bigNumbers[i+1];
            i++;
        } else {
            sum += bigNumbers[i];
        }
        i++;
    }

    i=0;
    while (i<smallNumbers.size()) {
        if(i==smallNumbers.size()-1) {
            sum += smallNumbers[i];
            break;
        }

        if(smallNumbers[i]+smallNumbers[i+1] <= smallNumbers[i]*smallNumbers[i+1]){
            sum += smallNumbers[i]*smallNumbers[i+1];
            i++;
        } else {
            sum += smallNumbers[i];
        }
        i++;
    }

    return sum;
}

int main() {

    int N;
    cin>>N;

    int num;
    for (int i = 0; i < N; ++i) {
        cin>>num;

        if(num>0) bigNumbers.push_back(num);
        else smallNumbers.push_back(num);
    }

    cout<<solution(N);

    return 0;
}
