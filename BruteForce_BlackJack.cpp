#include <iostream>
//브루트포스 - 블랙잭

using namespace std;
int main(){

    int N, M, num;
    int max=0, test=0;

    cin>>N>>M;

    int * numbers = new int[N];
    for(int i=0; i< N; i++){
        cin>>numbers[i];
    }

    for(int i=0;i<N-2;i++){
        for(int j=i+1;j<N-1;j++){
            for (int k = j+1; k < N; k++) {
                test = numbers[i] + numbers[j] + numbers[k];
                if(test <= M && test > max) max = test;
            }
        }
    }

    cout<<max<<endl;

    return  0;
}
