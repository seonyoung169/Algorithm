#include <iostream>
#include <vector>

// BOJ 1427 소트인사이드 (정렬 문제 : 수가 주어지면 자리 수를 내림차순 정렬) - 버블 정렬로 풀기

using namespace std;

void bubbleSort(vector<int> & numbers){
    int temp;

    for(int i=0; i<numbers.size()-1; i++){
        for(int j=0; j<numbers.size()-1-i; j++){
            if(numbers[j] < numbers[j+1]){
                temp = numbers.at(j);
                numbers[j] = numbers.at(j+1);
                numbers[j+1] = temp;
            }
        }
    }

    for(int i=0; i<numbers.size(); i++)
        cout<<numbers.at(i);

    cout<<endl;
}

int main(){
    int N, left, share;
    vector<int> numbers;

    cin>>N;

    while (!(N<10)){
        left = N % 10;
        numbers.push_back(left);
        N = N/10;
    }
    numbers.push_back(N);

    bubbleSort(numbers);
    return 0;
}
