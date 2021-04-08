#include<iostream>

using namespace std;

struct node{
    int val;
    node *left, *right;
    node(){
        val = 0;
        left = NULL;
        right = NULL;
    }
    node(int num){
        val = num;
        left = NULL;
        right = NULL;
    }
};

node *Node(int num){
    node *n = new node(num);
    return n;
}

bool isSame(node *T, node *S){
    if(S == NULL && T == NULL){
        return true;
    }else if(S == NULL | T == NULL){
        return false;
    }else if(T->val == S->val){
        return isSame(S->left,T->left) && isSame(S->right, T->right);
    }else{
        return false;
    }
}

bool isSubtree(node *T, node *S){
    if(S == NULL){
        return true;
    }else if(T == NULL){
        return false;
    }else if(isSame(S,T)){
        return true;
    }else{
        return isSubtree(T->left, S)|isSubtree(T->right, S);
    }
}

int main(){
    node *T = Node(26);  
    T->right         = Node(3);  
    T->right->right = Node(3);  
    T->left         = Node(10);  
    T->left->left     = Node(4);  
    T->left->left->right = Node(30);  
    T->left->right     = Node(6);

    node *S = Node(10);  
    S->right     = Node(6);  
    S->left     = Node(4);  
    S->left->right = Node(30); 

    cout << isSubtree(T,S) << endl;
    return 0;
}
