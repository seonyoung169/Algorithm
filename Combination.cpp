//
// Created by SEONYOUNG LEE on 2020/05/18.
//
#include <iostream>

//1-5에서 3개 수 뽑기, 조합 기초 알고리즘

#define MAX 5

int arr[MAX];
bool selected[MAX] = {false, };

using namespace std;

void print(){
    for(int i = 0; i<MAX;i++) {
        if(selected[i]) cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void DFS(int idx, int cnt){
    if(cnt == 3){
        print();
        return;
    }else{
        for(int i=idx; i<MAX; i++){
            if(selected[i]) continue;
            else{
                selected[i] = true;
                DFS(i, cnt+1);
                selected[i] = false;
            }
        }
    }
}
int main(){

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    DFS(0,0);

    return 0;
}
