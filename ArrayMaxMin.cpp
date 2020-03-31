#include <iostream>
//입력받은 정수 중 최대, 최소 출력

using namespace std;

void getMaxMin(int N, int * numArray);

int main() {
    //setup
    int N, num;
    cin >> N;

    int * numArray = new int[N];
    for(int i =0; i<N; i++){
        cin>>num;
        numArray[i] = num;
    }

    getMaxMin(N, numArray);
    return 0;
}

void getMaxMin(int N, int * numArray){
    int max = numArray[0], min = numArray[0];

    for(int i=1;i<N;i++){
        if(numArray[i] > max) max = numArray[i];
        if(numArray[i] < min) min = numArray[i];
    }

    cout<<min<<" "<<max<<endl;
}
