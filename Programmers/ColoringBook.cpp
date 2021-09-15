#include <vector>

// 프로그래머스 level 2 컬러링 북, cpp
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int M;
int N;
vector<vector<int>> map;

void bfs(vector<vector<bool>> & visited, int r, int c, int & size, int color){

    for(int i=0; i<4; i++){
        int nr = r + dy[i];
        int nc = c + dx[i];

        if(nr>=0 && nr<M && nc>=0 && nc<N && map[nr][nc] == color && !visited[nr][nc]){
            visited[nr][nc] = true;
            size++;
            bfs(visited, nr, nc, size, color);
        }
    }

    return;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    map = picture;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    M = m;
    N = n;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(picture[i][j] > 0 && !visited[i][j]){
                number_of_area++;
                visited[i][j] = true;
                int size = 1;
                bfs(visited, i, j, size, picture[i][j]);
                if(max_size_of_one_area < size) max_size_of_one_area = size;
            }
        }
    }

    vector<int> answer = {number_of_area, max_size_of_one_area};
    return answer;
}
