#include<iostream>
#include<vector>
#include<list>
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
    TreeNode *left, *right;
    int val;
    TreeNode(int num){
        val = num;left = nullptr;right = nullptr;
    }
};

TreeNode *newNode(int val){
    return new TreeNode(val);
}

vector<string> helper(TreeNode *root){
    vector<string> *l = new vector<string>;
    vector<string> *r = new vector<string>;
    if(root == nullptr){
        return *l;
    }else{
        if(root->left == nullptr && root->right == nullptr){
            l->push_back(to_string(root->val));return *l;
        }else{
            *l = helper(root->left);*r = helper(root->right);
            vector<string> *v = new vector<string>;
            for(string &s:*l){
                v->push_back(to_string(root->val) + s);
            }
            for(string &s:*r){
                v->push_back(to_string(root->val) + s);
            }
            return *v;
        }
    }
}

int path_sum(TreeNode *root){
    vector<string> nums(helper(root));int ans(0);
    for(string &s:nums){
        ans += stoi(s);
    }
    return ans;
}

//recursionでも綺麗にかける

int main(){
    TreeNode *root = newNode(6);  
    root->left = newNode(3);  
    root->right = newNode(5);  
    root->left->left = newNode(2);  
    root->left->right = newNode(5);  
    root->right->right = newNode(4);  
    root->left->right->left = newNode(7);  
    root->left->right->right = newNode(4);
    cout << path_sum(root) << endl;
    return 0;
}