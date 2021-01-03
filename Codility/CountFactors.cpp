#include <iostream>
#include <cmath>

//Codility Lesson 10 CountFactors 100% 맞음
using namespace std;

int solution(int N) {
    if(N==1) return 1;

    int count = 0;
    for(int i=1; i<sqrt(N); i++){
        if(N%i==0) count++;
    }

    count = count*2;
    int cut = sqrt(N);

    if(sqrt(N) - cut == 0) {
        count++;
    }

    return count;
}
int main() {

    cout<<solution(100);

    return 0;
}
