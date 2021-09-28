#include <iostream>
#include <vector>

// boj 5052 전화번호 목록, Trie 사용, 골드 4 
using namespace std;

struct TRIE {
    bool finish;
    TRIE * Node[26];
    TRIE() {
        finish = false;
        for (int i = 0; i < 26 ; ++i) Node[i] = NULL;
    }

    void insert(char * str){
        if (*str == NULL){
            finish = true;
            return;
        }

        int cur = *str - '0';
        if (Node[cur] == NULL){
            Node[cur] = new TRIE();
        }

        Node[cur]->insert(str+1);
    }

    bool check(char * str) {
        if(*str == NULL) return true;
        if (finish) return false;

        int cur = *str - '0';
        return Node[cur]->check(str+1);
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin>>N;

        char numbers[10001][11];
        TRIE * root = new TRIE();

        for (int j = 0; j < N; ++j) {
            cin>>numbers[j];
            root->insert(numbers[j]);
        }

        bool consistent = true;
        for (int j = 0; j < N; ++j) {
            if (!(root->check(numbers[j]))) {
                consistent = false;
                break;
            }
        }

        if (!consistent) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }

    return 0;
}
