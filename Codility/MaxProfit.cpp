#include <iostream>
#include <vector>
#include <algorithm>

// Codility Lesson 9 MaxProfit 100% 맞음
using namespace std;

bool desc(int a, int b){
    return a>b;
}

int solution(vector<int> &A) {
    if(A.empty() || A.size()==1) return 0;

    vector<int> profit(A.size() -1);
    int min = A[0];

    for(int i=1; i<A.size(); i++){
        profit[i-1] = A[i]-min;
        if(A[i] < min) min = A[i];
    }

    sort(profit.begin(), profit.end(), desc);

    if(profit[0]<0) return 0;
    else{
        return profit[0];
    }
}

int main() {
    vector<int> test = {23171, 21011, 21123, 21366, 21013, 21367};

    cout << solution(test) << '\n';

    return 0;
}
