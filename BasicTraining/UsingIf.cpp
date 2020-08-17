//
// Created by SEONYOUNG LEE on 06/11/2019.
//
#include <iostream>

using namespace std;

int main(){
    int score;
    char grade;
    cin>>score;

    if(100>= score&& score>=90) grade = 'A';
    else if(89>= score && score>=80) grade = 'B';
    else if(score>=70 && score<=79) grade = 'C';
    else if(score>=60 && score<=69) grade = 'D';
    else grade = 'F';

    cout<<grade<<endl;
    return 0;
}
