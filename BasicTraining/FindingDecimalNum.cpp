#include <iostream>
#include <math.h>
//수학2 - 소수 찾기
//소수 찾는 방법 1 : X 보다 작은 수로 다 나눠보기 -> 시간초과!
//소수 찾는 방법 2 : 에라토스테네스의 방법 이용 (n^2 + i*n)

using namespace std;

int main(){
    int M, N;
    cin>>M>>N;

    bool * checkArray = new bool[N+1];
    for(int i=0; i< N+1; i++) checkArray[i] = true;

    for(int i=2; i<= N+1; i++){
        if(checkArray[i]){
            if((unsigned int)pow(i,2) > N+1){
                break;
            }else{
                for (int j = (int)pow(i,2); j < N+1; ) {
                    checkArray[j] = false;
                    j = j+i;
                }
            }
        }
    }

    if(M == 1) M++;
    for (int k = M; k <= N+1; k++) {
        if (checkArray[k]) cout<<k<<" ";
    }
    cout<<endl;

    delete []checkArray;

    return  0;
}
