#include <iostream>
#include <string.h>

//BOJ 1012 DFS, 맞음!
using namespace std;

int M, N;
int ground[51][51];

void dfs(int x, int y){
    //ground 벗어났을 때
    if( x<1 || x>M || y<1 || y>N) return;
    if(ground[y][x] == 0) return;

    ground[y][x] = 0;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, K, dfsCnt;
    cin>>T;

    for(int i=0; i<T; i++){
        cin>>M>>N>>K;
        memset(ground, 0, sizeof(ground));

        int idx, idy;
        for(int j=0; j<K; j++){
            cin>>idx>>idy;
            ground[idy+1][idx+1] = 1;
        }

        dfsCnt = 0;
        for(int k=1; k<=N; k++){
            for(int h=1; h<=M; h++){
                if(ground[k][h] == 1){
                    dfsCnt++;
                    dfs(h,k);
                }
            }
        }

        cout<<dfsCnt<<'\n';
    }

    return 0;
}
