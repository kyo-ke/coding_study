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

struct treenode{
    int val;
    treenode *left;
    treenode *right;
    treenode(){
        val = 0;left = NULL;right = NULL;
    }
    treenode(int v){
        val = v;left = NULL;right = NULL;
    }
};



int main(){
    treenode root,child(10);
    vector<treenode> v;
    v.push_back(child);
    root.left = &child;
    cout << v[0].val << endl;
    return 0;
}