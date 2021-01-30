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


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v){
        val = v;next = NULL;
    }
};

ListNode *reverse_list_rec(ListNode * root){
    if(root->next != NULL){
        ListNode *tail;
        tail = reverse_list_rec(root->next);
        tail->next = root;
        root->next = NULL;
        return root;
    }else{
        return root;
    }
}

ListNode *reverse_list(ListNode *root){
    if(root == NULL){
        return NULL;
    }else{
        auto ans = root;
        while(ans->next != NULL){
            ans = ans->next;
        }
        reverse_list_rec(root);
        return ans;
    }
}

int main(){
    ListNode a(0);
    ListNode b(1);
    ListNode c(2);
    ListNode d(3);
    ListNode e(4);
    ListNode f(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    auto head = &a;
    head = reverse_list(head);
    while(head != NULL){
        cout << head->val << "->";head = head->next;
    }
    cout << endl;
    return 0;
}