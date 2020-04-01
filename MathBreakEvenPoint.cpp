#include <iostream>
//수학1 - 손익분기점 구하기

using namespace std;

int main(){
    int n, A, B, C;
    cin>>A>>B>>C;

    if(C <= B){
        n = -1;
    }else{
        n = A/(C-B) + 1;
    }

    cout<<n<<endl;
    return  0;
}
