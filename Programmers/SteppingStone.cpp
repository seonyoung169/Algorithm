#include <string>
#include <vector>
#include <algorithm>

// 프로그래머스 징검다리 건너기, Level 3, 이분탐색 이용
using namespace std;

bool isPossible(vector<int> stones, int k, int mid){
    int count = 0; 
    for(int i=0; i<stones.size(); i++){
        if(stones[i]-mid <= 0) count++;
        else count = 0;
        
        if(count>=k) return false;
    }
    
    return true;
}

int solution(vector<int> stones, int k) {
    vector<int> copy = stones;
    sort(copy.begin(), copy.end());
    
    int low = 1, high = copy[copy.size()-1];
    
    while(low <= high){
        int mid = (low + high) / 2;
        if(isPossible(stones, k, mid)){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    
    return low;
}
