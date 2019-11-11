//
// Created by SEONYOUNG LEE on 06/11/2019.
//
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int calculateCycle(int N);

int main(){
    //input
    int N;
    string strNum;

    cin>>N;
    if(N<10) strNum = '0'+to_string(N);
    else strNum = to_string(N);

    N = atoi(strNum.c_str());
    cout<<calculateCycle(N)<<endl;

    return 0;
}

int calculateCycle(int N){
    int originN = N;
    int bigNum, smallNum, sumNum;
    int cycle = 0;
    bigNum = N/10;
    smallNum = N%10;

    do{
        sumNum = bigNum + smallNum;
        bigNum = smallNum;
        smallNum = sumNum%10;

        N = bigNum*10 + smallNum;
        cycle++;
    }while(N!=originN);

    return cycle;
}
