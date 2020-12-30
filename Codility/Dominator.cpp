#include <iostream>
#include <vector>
#include <map>

//Codility Leader #1 Dominator 100% 맞
using namespace std;

int solution(vector<int> &A) {
    int answer = -1;
    int half = A.size() / 2;
    int domimator;
    bool find = false;

    map<int, int> countMap;
    vector<int> copy(A.size());
    copy.assign(A.begin(), A.end());

    for(unsigned int i=0; i<copy.size(); i++){
        countMap[copy[i]] = countMap[copy[i]]+ 1;
    }

    map<int, int>::iterator iter;
    for(iter = countMap.begin(); iter != countMap.end(); iter++){
        if(iter->second > half){
            domimator = iter->first;
            find = true;
        }
    }

    if (find){
        for (unsigned int i = 0; i < A.size(); i++) {
            if (A[i] == domimator){
                answer = i;
                break;
            }
        }
    }

    return answer;
}
int main() {
    vector<int> testArray = {2,1,1,3};

    cout<<solution(testArray)<<'\n';

    return 0;
}
