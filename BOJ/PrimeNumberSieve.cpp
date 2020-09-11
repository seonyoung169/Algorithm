#include <iostream>
#include <vector>
#include <algorithm>

// BOJ 1978번 소수 찾기 - 에라토스테네스 체 이용, 맞음!
using namespace std;

void primeNumberSieve(vector<int> & array, int max){

    for(int i=2; i <= max; i++){
        if(array[i] == 0) continue;
        else{
            for(int j= i+i; j<=max; j+=i){
                array[j] = 0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, temp, result = 0;
    vector<int> numbers;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>temp;
        numbers.push_back(temp);
    }
    sort(numbers.begin(), numbers.end());

    vector<int> array(numbers.at(N-1)+1);
    for(int i=2; i<array.size(); i++){
        array[i] = i;
    }

    primeNumberSieve(array, numbers.at(N-1));

    for(int i=0; i<numbers.size(); i++){
        if(array[numbers.at(i)] != 0) result++;
    }

    cout<<result<<'\n';

    return 0;
}
