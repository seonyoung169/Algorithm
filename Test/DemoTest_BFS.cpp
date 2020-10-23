#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

//nhn 데모 시험 bfs
using namespace std;

int areasize;

void bfs(int sizeOfMatrix, int ** matrix, int x, int y){
    if(x<0 || x>=sizeOfMatrix || y<0 || y>=sizeOfMatrix) return;
    if(matrix[y][x] == 0) return;

    matrix[y][x] = 0;
    areasize++;
    bfs(sizeOfMatrix, matrix, x+1, y);
    bfs(sizeOfMatrix, matrix, x-1, y);
    bfs(sizeOfMatrix, matrix, x, y+1);
    bfs(sizeOfMatrix, matrix, x, y-1);
}
void solution(int sizeOfMatrix, int **matrix) {
    // TODO: 이곳에 코드를 작성하세요.
    int area = 0;
    vector<int> sizeresult;

    for(int i=0; i<sizeOfMatrix; i++){
        for(int j=0; j<sizeOfMatrix; j++){
            if(matrix[i][j] == 1){
                areasize=0;
                area++;
                bfs(sizeOfMatrix, matrix, j,i);
                sizeresult.push_back(areasize);
            }
        }
    }
    sort(sizeresult.begin(), sizeresult.end());

    cout<<area<<'\n';
    if(!sizeresult.empty()){
        for(int i=0; i<sizeresult.size(); i++){
            cout<<sizeresult[i]<<' ';
        }
    }
    cout<<'\n';
}

struct input_data {
    int sizeOfMatrix;
    int **matrix;
};

void process_stdin(struct input_data& inputData) {
    string line;
    istringstream iss;

    getline(cin, line);
    iss.str(line);
    iss >> inputData.sizeOfMatrix;

    inputData.matrix = new int*[inputData.sizeOfMatrix];
    for (int i = 0; i < inputData.sizeOfMatrix; i++) {
        getline(cin, line);
        iss.clear();
        iss.str(line);
        inputData.matrix[i] = new int[inputData.sizeOfMatrix];
        for (int j = 0; j < inputData.sizeOfMatrix; j++) {
            iss >> inputData.matrix[i][j];
        }
    }
}

int main() {
    struct input_data inputData;
    process_stdin(inputData);

    solution(inputData.sizeOfMatrix, inputData.matrix);
    return 0;
}
