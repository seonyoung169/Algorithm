#include <iostream>
#include <vector>

// BOJ 11004번 K번째 수 -> 퀵 정렬로 풀기 (BOJ 상에선 시간초과)
using namespace std;

void quickSort(vector<int> & numbers, int start, int end){
    if(start >= end) return;

    int pivot;
    int i = start+1, j = end, temp;

    while(i <= j){ //역전될 때 까지
        pivot = numbers.at(start);

        while (i <= end &&numbers.at(i) <= pivot) {
            i++;
        }
        while (numbers.at(j) >= pivot && j > start) {
            j--;
        }

        if(i>j){ //역전되었으면 p값과 p 보다 작은 값 교환
            temp = numbers.at(j);
            numbers[j] = pivot;
            numbers[start] = temp;
        }else{ //정상 교환
            temp = numbers.at(j);
            numbers[j] = numbers.at(i);
            numbers[i] = temp;
        }

        quickSort(numbers, start, j-1);
        quickSort(numbers, j+1, end);
    }

}

int main(){
    int N, K, temp;
    vector<int> numbers;

    cin>>N>>K;

    for(int i=0; i<N; i++){
        cin>>temp;
        numbers.push_back(temp);
    }

    quickSort(numbers, 0, N-1);
    cout<<numbers.at(K-1)<<endl;

    return 0;
}
