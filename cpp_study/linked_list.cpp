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

//template <typename T>
struct listnode{
    listnode *next;
    //T val;
    int val;
    //listnode(T v){
    //    val = v;
    //}
    listnode(int v){
        val = v;
    }
};

int main(){
    //listnode<int> l(10);
    listnode h(10),t(11);
    h.next = &t;
    cout << h.next->val << endl;
}