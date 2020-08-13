#include <iostream>
#include <vector>

// BOJ 11650번 좌표 정렬하기 - 버블 정렬로 풀어봄 (시간 초과)

using namespace std;

void swap(pair<int, int> & point1, pair<int, int> & point2){
    int tempX, tempY;
    tempX = point1.first;
    tempY = point1.second;

    point1.first = point2.first;
    point1.second = point2.second;

    point2.first = tempX;
    point2.second = tempY;
}

void bubbleSort(vector<pair<int, int>> & coordinates){

    for(int i=0; i<coordinates.size()-1; i++){
        for(int j=0; j<coordinates.size()-1-i; j++){

            if(coordinates[j].first > coordinates[j+1].first){
                swap(coordinates.at(j), coordinates.at(j+1));
            }
            else if(coordinates[j].first == coordinates[j+1].first){
                if(coordinates[j].second > coordinates[j+1].second){
                    swap(coordinates.at(j), coordinates.at(j+1));
                }
            }
        }
    }

    for(int i=0; i<coordinates.size(); i++)
        cout<<coordinates[i].first<<" "<<coordinates[i].second<<endl;

}
int main(){
    int N, X, Y;
    vector<pair<int, int>> coordinates;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>X>>Y;
        coordinates.push_back(make_pair(X,Y));
    }

    bubbleSort(coordinates);
    return 0;
}
