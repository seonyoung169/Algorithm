#include <string>
#include <vector>
#include <sstream>
#include <cmath>

// 프로그래머스 k 진수에서 소수 개수 구하기, level 2 
using namespace std;

string convert(int n, int k){
    string result = "";

    while (n>=k){
        int left = n%k;
        result = to_string(left) + result;
        n = n/k;
    }
    result = to_string(n) + result;

    return result;
}

vector<string> split(string str, char del){
    vector<string> result;
    string temp;
    stringstream ss(str);

    while (getline(ss, temp, del)) {
        if (temp != "") result.push_back(temp);
    }

    return result;
}

bool isPrime(long num){
    if (num==1) return false;
    if (num==2) return true;

    for (long i = 2; i <= sqrt(num); ++i) {
        if (num%i==0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    string converted = convert(n, k);
    vector<string> numbers = split(converted, '0');

    for (int i = 0; i < numbers.size(); ++i) {
        if (isPrime(stol(numbers[i]))) answer++;
    }

    return answer;
}
