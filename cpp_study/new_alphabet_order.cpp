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


unordered_map<char, int> n_order;

struct c_comp{
    bool operator()(const char &a, const char & b)const{
        return n_order[a] < n_order[b];
    }
};

struct s_comp{
    bool operator()(const string &a, const string &b)const{
        int i(0);
        if(a.size() == 0){
            return true;
        }else if(b.size() == 0){
            return false;
        }else{
            while(a[i] == b[i]){
                i++;
                if(i == a.size()){
                    return true;
                }else if(i == b.size()){
                    return false;
                }
            }
            c_comp comp;
            return comp(a[i], b[i]);
        }
    }
};


int main(){
    string order = "habcldefgijkmnopqrstuvwxyz";
    vector<string> v ={"hello","leetcode","ello"};
    int i=0;
    while(i < order.size()){
        n_order[order[i]] = i;
        i++;
    }
    sort(v.begin(), v.end(), s_comp());

    for(auto &s:v){
        cout << s << endl;
    }
    return 0;
}