

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

class stack_getmin{
    stack<int> s;
    int m;
    public:
    void push(int i){
        if(s.empty()){
            m = i;s.push(i);
        }else if(m > i){
            s.push(i*2 - m);m = i;
        }else{
            s.push(i);
        }
    }
    bool empty(){
        return s.empty();
    }
    int top(){
        if(s.top() < m){
            return m;
        }else{
            return s.top();
        }
    }
    void pop(){
        if(s.top() < m){
            m = 2*m-s.top();
            s.pop();
        }else{
            s.pop();
        }
    }
    int get_min(){
        if(s.empty()){
            return INT_MIN;
        }else{
            return m;
        }
    }
};


int main(){
    stack_getmin s;
    s.push(5);
    s.push(7);
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(3);
    s.push(2);
    while(!s.empty()){
        cout << s.get_min() << endl;
        s.pop();
    }
    return 0;
}