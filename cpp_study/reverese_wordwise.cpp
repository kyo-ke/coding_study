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


void reverse_words(string & s){
    reverse(s.begin(), s.end());
    string::iterator head,tail;
    head = s.begin();
    while(head != s.end()){
        while(*head == ' ' && s.end() != head){
            head++;
        }
        if(head == s.end()){
            break;
        }
        tail = head;
        while(*tail != ' ' && tail != s.end()){
            tail++;
        }
        reverse(head, tail);head = tail;
    }
}

void reverse_words2(string& s){
    stack<string> st;
    string ans = "";
    string::iterator head, tail;head = s.begin();
    while(head != s.end()){
        cout << "now" << endl;
        while(*head == ' ' && head != s.end()){
            head++;
        }
        if(head == s.end()){
            break;
        }
        tail = head;
        while(*tail != ' ' && tail != s.end()){
            tail++;
        }
        st.push(string (head, tail));head = tail;
    }
    while(!st.empty()){
        ans += st.top();st.pop();
        ans += " ";
    }
    tail = ans.end()-1;
    *tail = '\0';
    s = ans;
}

int main(){
    string s = "y    this is a pen ";
    reverse_words2(s);
    cout << s << endl;
    return 0;
}