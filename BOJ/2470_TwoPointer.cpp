#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

pair<long, long> solution(vector<long> numbers){
    pair<long, long> answer;

    sort(numbers.begin(), numbers.end());
    long  min = 2147483647;
    int left = 0, right = numbers.size()-1;

    while (left<right){
        int sum = numbers[left] + numbers[right];

        if (min > abs(sum)){
            min = abs(sum);
            answer.first = numbers[left];
            answer.second = numbers[right];
        }

        if (sum < 0) left++;
        else right--;

    }

    return answer;
}


int main() {
    int N;
    cin>>N;

    vector<long> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin>>numbers[i];
    }

    pair<long, long> answer = solution(numbers);

    cout<<answer.first<<' '<<answer.second;

    return 0;
}
