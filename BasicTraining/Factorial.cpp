#include <iostream>
//재귀 함수 

using namespace std;

int princFactorial(int N);

int main(){
    int N;
    cin>>N;

    cout<<princFactorial(N)<<endl;

    return 0;
}
int princFactorial(int N){
    if(N == 0) return 1;
    else return N*princFactorial(N-1);
}
