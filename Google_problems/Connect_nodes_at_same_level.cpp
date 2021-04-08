#include<iostream>
#include<queue> 
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right, *rightnode;
        TreeNode(int num){
            val = num;
            left = nullptr;right = nullptr;
            rightnode = nullptr;
        }
};

TreeNode *newNode(int num){
    return new TreeNode(num);
}

void buildright(TreeNode *root){
    int count;
    queue<TreeNode*> q;
    TreeNode *lastNode(nullptr);
    q.push(root);
    while(!q.empty()){
        count = q.size();
        while(count > 0){
            if(lastNode != nullptr){
                lastNode->rightnode = q.front();
            }
            lastNode = q.front();q.pop();
            if(lastNode->left != nullptr){
                q.push(lastNode->left);
            }
            if(lastNode->right != nullptr){
                q.push(lastNode->right);
            }
            count--;
        }
        lastNode->rightnode = nullptr;
        lastNode = nullptr;
    }
}

void printer(TreeNode* root){
    if(root != nullptr){
        TreeNode *nownode(root);
        while(nownode != nullptr){
            cout << nownode->val << "->";
            nownode = nownode->rightnode;
        }
        cout << "nullptr" << endl;
        printer(root->left);
    }
}


int main(){
    TreeNode *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    buildright(root);
    printer(root);
    
    return 0;
}
