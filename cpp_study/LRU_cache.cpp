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
#include<list>
using namespace std;


//cacheの値をmapに見にいく
//mapがiterator返す
struct LRUcache{
     list<int> dq;
     unordered_map<int, list<int>::iterator> m;
     int c_size;
     LRUcache(int s){
         c_size = s;
     }
     void use(int i){
         if(m.find(i) == m.end()){
             if(dq.size() < c_size){
                 dq.push_back(i);
                 m[i] = dq.end();m[i]--;
             }else{
                 m.erase(dq.front());
                 dq.pop_front();
                 dq.push_back(i);
                 m[i] = dq.end();m[i]--;
             }
         }else{
             dq.erase(m[i]);
             dq.push_back(i);
             m[i] = dq.end();m[i]--;
         }
     } 

     void print_cache(){
         auto it=dq.begin();
         while(it != dq.end()){
             cout << *it << endl;
             it++;
         }
     }
};


int main(){

    LRUcache c(3);
    c.use(1);
    c.use(2);
    c.use(3);
    c.use(4);
    c.use(5);
    c.use(4);
    c.use(1);
    c.print_cache();
    return 0;
}