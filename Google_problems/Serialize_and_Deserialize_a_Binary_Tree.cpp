#include<iostream>
#include<string>

using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(){
            val = 0;
            left = nullptr;right = nullptr;
        }
        TreeNode(int num){
            val = num;
            left = nullptr;right = nullptr;
        }
};

TreeNode *newNode(int num){
    return new TreeNode(num);
}

void helper(TreeNode *root, string &ans){
    if(root == nullptr){
        ans += '/';
    }else{
        ans += '0' + root->val;
        helper(root->left, ans);
        helper(root->right, ans);
    }
}

string serialize(TreeNode *root){
    string ans("");
    helper(root, ans);
    return ans;
}

TreeNode *desirialize_(string s, int &p){
    if(p >= s.size()){
        return nullptr;
    }else if(s[p] == '/'){
        p++;
        return nullptr;
    }else{
        TreeNode *node = newNode(s[p] - '0');
        p++;
        node->left = desirialize_(s,p);
        node->right = desirialize_(s,p);
        return node;
    }
}

TreeNode *desirialize(string s){
    int p=0;
    return desirialize_(s, p);
}

void preorder_(TreeNode *root){
    if(root != nullptr){
        cout << (char)('0' + root->val) << ", ";
        preorder_(root->left);
        preorder_(root->right);
    }
}

void preorder(TreeNode *root){
    preorder_(root);
    cout << endl;
}

int main(){
    TreeNode *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
    cout << serialize(root) << endl;
    preorder(root);
    preorder(desirialize(serialize(root)));
    return 0;
}
