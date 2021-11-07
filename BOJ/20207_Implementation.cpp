#include <iostream>
#include <vector>

//boj 20207 달력, 구현, 실버 1
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    int N, S, E;
    cin>>N;

    vector<int> task(367, 0);

    for (int i = 0; i < N; ++i) {
        cin>>S>>E;

        for (int j =S; j <=E; ++j) task[j]++;
    }

    int from = -1, to = -1, height = 0;
    for (int i = 1; i <=366 ; ++i) {
        if (task[i]>0 && task[i-1]==0) from = i;
        if (height<task[i]) height = task[i];
        if (task[i-1]>0 && task[i]==0) {
            to = i-1;
            answer += (to-from+1)*height;
            height = 0;
        }
    }

    cout<<answer;

    return 0;
}
