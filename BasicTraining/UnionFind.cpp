#include <iostream>
#include <vector>

//union - find (합집합 찾기) algorithm
using namespace std;

//부모 노드 번호를 반환하는 함수
int getParent(vector<int> & parents, int x){
    if(parents[x] == x) return x; // 최종 부모 노드이면 반환
    else return getParent(parents, parents[x]);
}
//두 노드를 연결시키는 함수
void unionParent(vector<int> & parents, int a, int b){
    a = getParent(parents, a);
    b = getParent(parents, b);
    if(a < b) parents[b] = a;
    else parents[a] = b;
}

//두 노드 a, b가 같은 그래프 안에 있는지 확인하는 함수
bool findParent(vector<int> & parents, int a, int b){
    a = getParent(parents, a);
    b = getParent(parents, b);
    if(a == b) return 1;
    else return 0;
}

int main(){
    vector<int> parents(11);
    for(int i=0; i<11; i++){
        parents[i] = i;
    }

    unionParent(parents, 1, 2);
    unionParent(parents, 2, 3);
    unionParent(parents, 3, 4);

    unionParent(parents, 5, 6);
    unionParent(parents, 6, 7);
    unionParent(parents, 7, 8);

    cout<<"5 - 1 ? : "<<findParent(parents, 1,5)<<"\n";
    cout<<"1 - 3 ? : "<<findParent(parents, 1,3)<<'\'n';

    return 0;
}
