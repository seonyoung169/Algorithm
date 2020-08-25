#include <iostream>
#include <vector>

//백준 11650 - 힙 정렬 이용, BOJ 상에선 시간 
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
void heapSort(vector<pair<int, int>> & points){
    int nodes = points.size(), root, idx;

    //최대 힙 구조 생성하기
    for(int i=1; i < nodes; i++){
        idx = i;

        do{
            root = (idx-1) / 2;
            if(points.at(idx).first > points.at(root).first){
                swap(points.at(idx), points.at(root));
            }else if (points.at(idx).first == points.at(root).first){
                if(points.at(idx).second > points.at(root).second){
                    swap(points.at(idx), points.at(root));
                }
            }
            idx = root;
        }while (idx != 0);
    }

    for(int i = nodes-1; i>0; i--){
        swap(points.at(0), points.at(i));     // 마지막 노드랑 루트 노드 교체
        root = 0;
        idx = 2*root + 1;

        do{
            if(idx < i-1){
                // 두 자식 노드 중 더 큰 노드 찾기
                if(points.at(idx).first < points.at(idx+1).first){
                    idx++;
                } else if (points.at(idx).first == points.at(idx+1).first){
                    if(points.at(idx).second < points.at(idx+1).second){
                        idx++;
                    }
                }
            }

            if(idx < i){
                // 루트 노드보다 자식 노드가 크면 교체 (x 값 동일하면 y 값으로 비교)
                if(points.at(idx).first > points.at(root).first){
                    swap(points.at(idx), points.at(root));
                } else if (points.at(idx).first == points.at(root).first){
                    if(points.at(idx).second > points.at(root).second){
                        swap(points.at(idx), points.at(root));
                    }
                }
            }

            root = idx;
            idx = 2*root + 1;
        }while (idx < i);
    }

}

int main(){
    int N, X, Y;
    vector<pair<int, int>> points;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>X>>Y;
        points.push_back(make_pair(X,Y));
    }

    heapSort(points);

    for(int i=0; i<N; i++){
        cout<<points.at(i).first<<" "<<points.at(i).second<<endl;
    }

    return 0;
}
