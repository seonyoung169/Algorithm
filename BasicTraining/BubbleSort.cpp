#include <iostream>
#include <vector>

//백준 정렬 - 수 정렬하기1 : N개의 수를 입력받아 오름 차순으로 정렬
//버블소트 사용

using namespace std;

void bubbleSort(vector<int> numArray, int N);

int main(){
    int N, num;
    cin>>N;

    vector<int> numArray;
    for(int i=0; i<N; i++) {
        cin>> num;
        numArray.push_back(num);
    }

    bubbleSort(numArray, N);

    return  0;

}
void bubbleSort(vector<int> numArray, int N){
    int temp;

    for(int i=0; i<N-1;i++){
        for(int j = 0; j < N-1-i;j++){
            if(numArray[j]>numArray[j+1]){ //순서가 바뀌어 있으면 교체
                temp = numArray[j];
                numArray[j] = numArray[j+1];
                numArray[j+1] = temp;
            }
        }
    }

    for(int i=0;i<N;i++) cout<<numArray[i]<<'\n';
}
