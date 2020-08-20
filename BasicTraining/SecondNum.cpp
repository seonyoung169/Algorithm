#include <iostream>
#include <algorithm>

//세 수 중 두번째로 큰 수 출력

using namespace std;

int main() {
    int numArray[3];
    int num;

    for(int i=0; i<3; i++){
        cin>>num;
        numArray[i] = num;
    }

    sort(numArray, numArray+3);
    cout<<numArray[1]<<endl;

    return 0;
}
