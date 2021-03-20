#include<iostream>
#include<vector>

using namespace std;

class TreeNode{
    public:
        char val;
        TreeNode *left, *right;
        TreeNode(){
            val = '/';
            left = nullptr;right = nullptr;
        }
        TreeNode(char num){
            val = num;
            left = nullptr;right = nullptr;
        }
};

TreeNode *newNode(char num){
    return new TreeNode(num);
}

TreeNode *build(vector<char> preorder, vector<char> inorder){
    if(preorder.size() == 1){
        return newNode(preorder[0]);
    }else{
        int p(0);
        while(preorder[0] != inorder[p]){
            p++;
        }
        if(p == 0){
            TreeNode *node = newNode(preorder[0]);
            vector<char> pre(preorder.begin()+1, preorder.end());
            vector<char> ino(inorder.begin()+1, inorder.end());
            node->right = build(pre,ino);
            return node;
        }else if(p == inorder.size()-1){
            TreeNode *node = newNode(preorder[0]);
            vector<char> pre(preorder.begin()+1, preorder.end());
            vector<char> ino(inorder.begin(), inorder.end()-1);
            node->left = build(pre,ino);
            return node;
        }else{
            cout << "now" << preorder[0] <<  endl;
            TreeNode *node = newNode(preorder[0]);
            vector<char> pre(preorder.begin()+1, preorder.begin() + p + 1);
            vector<char> ino(inorder.begin(), inorder.begin() + p);
            node->left = build(pre,ino);
            vector<char> pre_(preorder.begin()+1+p, preorder.end());
            vector<char> ino_(inorder.begin()+1+p, inorder.end());
            node->right = build(pre_,ino_);
            return node;
        }
    }
}


void preorder_(TreeNode *root){
    if(root != nullptr){
        cout << root->val << ", ";
        preorder_(root->left);
        preorder_(root->right);
    }
}

void preorder(TreeNode *root){
    preorder_(root);
    cout << endl;
}

int main(){
    vector<char> pre{ 'A', 'B', 'D', 'E', 'C', 'F' };
    vector<char> ino{ 'D', 'B', 'E', 'A', 'F', 'C' };
    TreeNode *root = build(pre, ino);
    preorder(root);
    return 0;
}


