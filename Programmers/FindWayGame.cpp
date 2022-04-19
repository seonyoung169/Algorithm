#include <string>
#include <vector>
#include <algorithm>

// 프로그래머스 길찾기 게임, level3, Tree 순회 구현 
using namespace std;

class Node {
public:
    int data, x, y;
    Node * left = NULL;
    Node * right = NULL;

    Node(int _data, int _x, int _y)
            :data(_data), x(_x), y(_y)
    { }
};
bool byLevel(Node a, Node b){
    if (a.y == b.y){
        return a.x < b.x;
    }
    return a.y > b.y;
}

void insertNode(Node * root, Node * new_node){
    if(root->x > new_node->x){
        if(root->left == NULL){
            root->left = new_node;
            return;
        }
        insertNode(root->left, new_node);
    }else{
        if(root->right==NULL){
            root->right = new_node;
            return;
        }
        insertNode(root->right, new_node);
    }
}

void makePreorder(Node * node, vector<int> & pre){
    if (node==NULL) return;
    pre.push_back(node->data);
    makePreorder(node->left, pre);
    makePreorder(node->right, pre);
}

void makePostorder(Node * node, vector<int> & post){
    if (node==NULL) return;
    makePostorder(node->left, post);
    makePostorder(node->right, post);
    post.push_back(node->data);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node> nodeList;

    for (int i = 0; i < nodeinfo.size(); ++i) {  // Node 클래스로 만들어서 정렬
        nodeList.push_back(Node(i+1, nodeinfo[i][0], nodeinfo[i][1]));
    }
    sort(nodeList.begin(), nodeList.end(), byLevel);

    Node * root = &nodeList[0];
    for (int i = 1; i < nodeList.size(); ++i) {  // tree 구축
        insertNode(root, &nodeList[i]);
    }

    vector<int> preorder, postorder;
    makePreorder(root, preorder);
    makePostorder(root, postorder);

    answer = {preorder, postorder};

    return answer;
}
