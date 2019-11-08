//
// Created by SEONYOUNG LEE on 06/11/2019.
//

#include <iostream>
using namespace std;

int main(){
    int A, B, C;
    cin>>A>>B>>C;

    cout<<(A+B)%C<<endl<<(A%C +B%C)%C <<endl<<(A*B)%C<<endl<<(A%C * B%C)%C<<endl;

    return 0;
}

