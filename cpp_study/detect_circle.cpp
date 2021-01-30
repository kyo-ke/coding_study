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

int detect_circle(ListNode *root){
    if(root == NULL){
        return -1;
    }else if(root->next == NULL){
        return -1;
    }else if(root->next->next == NULL){
        return -1;
    }else{
        ListNode *fast, *slow;
        fast = root->next->next;slow = root->next;
        while(fast != slow){
            if(fast->next == NULL){
                fast = NULL;break;
            }else if(fast->next->next == NULL){
                fast = NULL;break;
            }else{
                fast = fast->next->next;slow = slow->next;
            }
        }
        if(fast == NULL){
            return -1;
        }else{
            slow = root;
            while(fast != slow){
                fast = fast->next;slow = slow->next;
            }
            return fast->val;
        }
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
    f.next = &a;
    cout << detect_circle(&a) << endl;
    return 0;
}