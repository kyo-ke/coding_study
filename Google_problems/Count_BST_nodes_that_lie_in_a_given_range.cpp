#include<iostream>

using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right;
        TreeNode(int num){
            val = num;
            left = nullptr;
            right = nullptr;
        }
};

TreeNode *newNode(int num){
    return new TreeNode(num);
}

void helper(TreeNode *root, int &m, int &M, int &i){
    if(root != nullptr){
        if(root->val <= M){
            helper(root->right, m, M, i);
        }
        if(root->val >= m){
            helper(root->left, m, M, i);
        }
        if(m <= root->val && root->val <= M){
            i++;
        }
    }
}

int count_node(TreeNode *root, int m, int M){
    int i(0);
    helper(root, m,M,i);
    return i;
}


int main(){
    TreeNode *root        = newNode(10);
    root->left        = newNode(5);
    root->right       = newNode(50);
    root->left->left  = newNode(1);
    root->right->left = newNode(40);
    root->right->right = newNode(100);
    int m(5), M(45);
    cout << "number of node in range of " << m << ", " << M << " is " << count_node(root, m ,M) << endl;
    return 0;
}
