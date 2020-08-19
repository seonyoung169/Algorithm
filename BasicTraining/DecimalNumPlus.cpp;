#include <iostream>
#include <math.h>
#include <vector>
//수학2 - 베르트랑 공준 (소수 찾기 응용)

using namespace std;

int main(){
    int n, N, decimalCnt;
    vector<int> result;
    cin>>n;
    bool * array;

    while(n != 0){
        N = 2*n;
        array = new bool[N+1];
        for(int i=0;i<N+1;i++) array[i] = true;

        for(int i=2;i<N+1;i++){
            if(array[i]){
                if((unsigned int)pow(i,2) > N) break;
                else{
                    for(int j = (unsigned int)pow(i,2); j<N+1; ){
                        array[j] = false;
                        j = j+i;
                    }
                }
            }
        }
        decimalCnt = 0;
        for(int k = n+1; k<N+1; k++){
            if(array[k]) decimalCnt++;
        }
        result.push_back(decimalCnt);

        cin>>n;
    }

    for(int i=0;i<result.size();i++) cout<<result.at(i)<<" ";
    cout<<endl;

    return  0;
}
