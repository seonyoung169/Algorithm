#include <iostream>
#include <vector>
#include <string>

// BOJ 1991번 - 이진트리 순회하기, 맞음
using namespace std;

typedef struct node * nodePointer;
typedef struct node{
    char data;
    nodePointer left;
    nodePointer right;
} Node;

void preorder(nodePointer ptr){
    if(ptr != NULL){
        cout<<ptr->data;
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(nodePointer ptr){
    if(ptr != NULL){
        inorder(ptr->left);
        cout<<ptr->data;
        inorder(ptr->right);
    }
}

void postorder(nodePointer ptr){
    if(ptr != NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->data;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    char key, left, right;

    cin>>N;
    vector<Node> tree(N);

    for(int i= 0; i <N; i++){
        cin>>key>>left>>right;
        int idx = key - 'A';
        tree[idx].data = key;

        if(left == '.'){
            tree[idx].left = NULL;
        }else{
            tree[idx].left = &tree[left-'A'];
        }

        if(right == '.'){
            tree[idx].right = NULL;
        }else{
            tree[idx].right = &tree[right-'A'];
        }
    }

    preorder(&tree[0]);
    cout<<'\n';
    inorder(&tree[0]);
    cout<<'\n';
    postorder(&tree[0]);
    cout<<'\n';

    return 0;
}
