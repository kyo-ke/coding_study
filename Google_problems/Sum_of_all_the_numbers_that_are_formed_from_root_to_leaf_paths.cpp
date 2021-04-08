#include<iostream>
#include<vector>
using namespace std;

class node
{
    public:
        int data;
        node *left, *right;
        node(int d)
        {
            data = d;
            left = nullptr;
            right = nullptr;
        }
        node()
        {
            data = NULL;
            left = nullptr;
            right = nullptr;
        }

};

node *newNode(int data){
    node *n = new node(data);
    return n;
}

//root should not be nullptr
void helper(node *root, int num,vector<int> &ans){
    if(root->left == nullptr && root->right == nullptr){
        ans.push_back(num*10 + root->data);
    }else if(root->right == nullptr){
        helper(root->left, num*10 + root->data, ans);
    }else if(root->left == nullptr){
        helper(root->right, num*10 + root->data, ans);
    }else{
        helper(root->left, num*10 + root->data, ans);
        helper(root->right, num*10 + root->data, ans);
    }
}

vector<int> form_from_root(node *root){
    vector<int> ans;
    if(root == nullptr){
        return ans;
    }else{
        helper(root, 0, ans);
        return ans;
    }
}

int main(){
   // if(NULL == 0){
   //     cout << "NULL is 0" << endl;

   // }else{
   //     cout << "NULL is not 0" << endl;
   // }
    node *root = newNode(6);  
    root->left = newNode(3);  
    root->right = newNode(5);  
    root->left->left = newNode(2);  
    root->left->right = newNode(5);  
    root->right->right = newNode(4);  
    root->left->right->left = newNode(7);  
    root->left->right->right = newNode(4); 
    vector<int> ans = form_from_root(root);
    for(int &i:ans){
        cout << i << endl;
    }
    return 0;
}
