#include <iostream>
#include <vector>

// BOJ 11004번 K번째 수 -> 삽입 정렬로 풀기 (BOJ 상에선 시간초과)

using namespace std;

int getKnumber(int K, vector<int> & numbers){
    int temp, j;

    for(int i=0; i<numbers.size()-1; i++){
        j = i;
        while (numbers.at(j) > numbers.at(j+1)){
            temp = numbers.at(j);
            numbers[j] = numbers.at(j+1);
            numbers[j+1] = temp;
            j--;

            if(j<0) break;
        }
    }

    return numbers.at(K-1);
}

int main(){
    int N, K, temp;
    vector<int> numbers;

    cin>>N>>K;

    for(int i=0; i<N; i++){
        cin>>temp;
        numbers.push_back(temp);
    }

    cout<<getKnumber(K, numbers)<<endl;
    return 0;
}
