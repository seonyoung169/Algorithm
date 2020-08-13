#include <iostream>
#include <vector>

// BOJ 1427 소트인사이드 (정렬 문제 : 수가 주어지면 자리 수를 내림차순 정렬) - 선택 정렬로 풀기

using namespace std;

void selectionSort(vector<int> & numbers){
    int max, temp, idx;
    bool changed;

    for(int i=0; i<numbers.size()-1; i++){
        max = numbers.at(i);
        changed = false;

        for(int j=i+1;j<numbers.size();j++){
            if(max < numbers.at(j)){
                max = numbers.at((j));
                idx = j;
                changed = true;
            }
        }
        if(changed){
            temp = numbers.at((i));
            numbers[i] = max;
            numbers[idx] = temp;
        }
    }

    for(int i=0; i<numbers.size(); i++){
        cout<<numbers.at(i);
    }
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

    selectionSort(numbers);
    return 0;
}
