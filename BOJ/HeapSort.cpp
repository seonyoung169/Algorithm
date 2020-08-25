#include <iostream>
#include <vector>

// BOJ 2750번 - 수 정렬, 힙 정렬 이용해서 풀기, 맞음 / (2751 수 정렬2 에선 시간초과, 10898 수 정렬3 에선 메모리 초과)
using namespace std;

void swap(int & data1, int & data2){
    int temp = data1;
    data1 = data2;
    data2 = temp;
}
void heapSortion(vector<int> & data){
    int size = data.size();
    //입력 받은 데이터로 최대 힙 구조 먼저 생성
    for(int i = 1; i<=size-1; i++){
        int idx = i, root, temp;

        do{
            root = (idx-1)/2;
            if(data.at(root) < data.at(idx)){
                swap(data.at(root), data.at(idx));
            }
            idx = root;
        }while(idx!= 0);
    }

    //root 원소를 제일 마지막으로 보내고 하나씩 줄여가면서 다시 힙 생성
    for(int i = size-1; i>0; i--){
        int temp = data.at(0);
        data[0] = data.at(i);
        data[i] = temp;

        int root = 0, idx;
        do{
            idx = 2 * root + 1;
            if(idx < i-1 && data.at(idx) < data.at((idx+1))){
                idx++;
            }

            if(idx < i && data.at(root) < data.at(idx)){
                //root 와 idx 값 교환
                swap(data.at(root), data.at(idx));
            }
            root = idx;

        }while (idx < i);
    }
}

int main(){
    int N, num;
    vector<int> data;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>num;
        data.push_back(num);
    }

    heapSortion(data);

    for(int i = 0; i<N; i++)
        cout<<data.at(i)<<endl;

    return 0;
}
