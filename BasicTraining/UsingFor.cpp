//
// Created by SEONYOUNG LEE on 06/11/2019.
//
#include <iostream>

using namespace std;

int main(){
    int N, X, num;
    cin>> N>>X;
    int * array = new int[N];

    for(int i=0;i<N;i++){
        cin>>num;
        array[i] = num;

        if(X>num) cout<<num<<" ";
    }

    cout<<endl;
    return 0;
}
