#include <iostream>
#include <vector>

// boj 1244 스위치 켜고 끄기, 실버3, implementation
using namespace std;

vector<int> light;

void boy(int num){
    int count = 1, idx = num;

    while (idx < light.size()){
        bool on = light[idx];
        light[idx] = !on;

        count++;
        idx = num*count;
    }
}

void girl(int num){
    bool on = light[num];
    light[num] = !on;

    int left = num-1, right = num+1;
    while (left>=1 && right<light.size()){
        if (light[left] != light[right]) break;
        on = light[left];
        light[left] = !on;
        light[right] = !on;

        left--, right++;
    }
}

void operateLight(vector<pair<int, int>> student){
    for (int i = 0; i < student.size(); ++i) {
        if (student[i].first == 1) boy(student[i].second);
        else girl(student[i].second);
    }
}

int main() {
    int N,M;
    cin>>N;

    light.assign(N+1, 0);
    for (int i = 1; i <= N; ++i) cin>>light[i];

    cin>>M;
    vector<pair<int, int>> student(M);
    for (int i = 0; i < M; ++i) cin>>student[i].first>>student[i].second;

    operateLight(student);

    int row = N/20 + 1;
    for (int i = 0; i < row; ++i) {
        int j = 20*i+1;
        while (j<light.size() && j-(20*i)<=20){
            cout<<light[j++]<<' ';
        }
        cout<<'\n';
    }


    return 0;

}
