#include <iostream>
#include <vector>
#include <string>

// boj 10994 별찍기-19, 실버 4 
using namespace std;

void printEven(int row, int size) {
    int edge = min(row, size+1-row);
    for (int i = 1; i <=size ; ++i) {
        if (i%2 == 0) cout<<' ';
        else {
            int left = size+1-i;
            if (left<edge || i<edge) cout<<'*';
            else cout<<' ';
        }
    }
}
void printOdd(int row, int size){
    int left = size+1-row;
    int from = min(left, row), to = max(left, row);

    for (int i = 1; i <=size ; ++i) {
        if (i%2==1) cout<<'*';
        else {
            if (i>=from && i<=to) cout<<'*';
            else cout<<' ';
        }
    }
}

int main() {
    int N;
    cin>>N;


    vector<string> answer;

    if (N==1){
        cout<<'*'<<'\n';
    } else {
        int size = 4*N-3;
        for(int i=1; i<=size; i++){
            if (i%2==0) printEven(i,size);
            else printOdd(i,size);
            cout<<'\n';
        }
    }

    return 0;
}
