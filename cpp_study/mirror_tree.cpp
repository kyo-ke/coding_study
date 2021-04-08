#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<stack>
#include<random>
#include<iterator>
#include <algorithm>
#include <functional>
#include <cassert>
#include <iomanip>
#include<unordered_map>
#include<bitset>
using namespace std;


struct TreeNode{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int num){
        val = num;left = NULL;right = NULL;
    }
};


//コメントアウトは失敗例
TreeNode *mirror_tree_(TreeNode *root){
    if(root != NULL){
        cout << root-> val << endl;
        TreeNode *nt = new TreeNode(root->val);
        //TreeNode nt(root->val);
        nt->left = mirror_tree_(root->right);
        nt->right = mirror_tree_(root->left);
        //nt.left = mirror_tree_(root->right);
        //nt.right = mirror_tree_(root->left);
        return nt;
        //return &nt;
    }else{
        return NULL;
    }
}

TreeNode *mirror_tree(TreeNode *root){
    return mirror_tree_(root);
    
}

void print_tree(TreeNode *root){
    queue<TreeNode*> q;
    int q_size;
    TreeNode *nt;
    q.push(root);
    while(!q.empty()){
        q_size = q.size();
        for(int i=0;i<q_size; i++){
            nt = q.front();q.pop();
            cout << nt->val << " ";
            if(nt->left != NULL){
                q.push(nt->left);
            }
            if(nt->right != NULL){
                q.push(nt->right);
            }
        }
        cout << endl;
    }
}

int main(){
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    a.left = &b;a.right = &c;
    b.left = &d;b.right = &e;
    c.left = &f;
    print_tree(&a);
    print_tree(mirror_tree(&a));
    return 0;
}