#include<iostream>

using namespace std;

struct node{
    int val;
    node *left, *right;
    node(){
        val = 0;
        left = NULL;right = NULL;
    }
    node(int num){
        val = num;
        left = NULL;
        right = NULL;
    }
};

int helper(node *root1, node * root2){
bool check_duplicate(node *root){
    if(root == NULL || helper(root->left, root->right))
    return true;
}

int main(){
    node n(10);
    cout << n.val << endl;
    return 0;
}
