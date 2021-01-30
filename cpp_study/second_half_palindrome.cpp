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


bool half_parindrome(string s){
    int h(s.size()/2);
    string half (s.substr(h));string rev(half);reverse(rev.begin(), rev.end());
    cout << rev << endl;
    cout << half << endl;
    return half == rev;
}

bool half_parindrome2(string s){
    int h(s.size()/2), t(s.size()-1);
    while(h < t){
        if(s[h] == s[t]){
            h++;t--;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    if(half_parindrome2(s)){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
}