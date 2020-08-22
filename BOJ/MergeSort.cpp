#include <iostream>
#include <vector>

// 백준 2751번 - 병합 정렬로 풀기, 맞음!

using namespace std;

vector<int> sorted;

void merge(vector<int> & numbers, int m, int mid, int n){
    int i = m, j = mid +1, k = m;

    while (i <= mid && j<= n){
        if(numbers.at(i) < numbers.at(j)){
            sorted[k] = numbers.at(i);
            i++;
        }else{
            sorted[k] = numbers.at(j);
            j++;
        }
        k++;
    }

    if(i > mid){
        for(int h = j; h<= n; h++){
            sorted[k] = numbers.at(h);
            k++;
        }
    }else{
        for(int h = i; h<=mid; h++){
            sorted[k] = numbers.at(h);
            k++;
        }
    }

    for(int t = m; t<=n; t++){
        numbers[t] = sorted.at(t);
    }
}
void mergeSort(vector<int> & numbers, int m, int n){

    if(m<n){
        int mid = (m+n) / 2;
        mergeSort(numbers, m, mid);
        mergeSort(numbers, mid+1, n);
        merge(numbers, m, mid, n);
    }
}
int main(){

    int N, temp;
    vector<int> numbers;

    cin>>N;
    sorted.assign(N, 0);

    for(int i=0; i<N ; i++){
        cin>>temp;
        numbers.push_back(temp);
    }

    mergeSort(numbers, 0, N-1);

    for(int i=0; i<numbers.size(); i++){
        cout<<numbers.at(i)<<" ";
    }
    cout<<endl;

    return 0;
}
