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

void swap(int &a, int &b){
    if(a != b){a ^= b; b ^= a; a ^= b;}
}


void sort_123(vector<int> &v){
    int i(0),j(0),k(v.size()-1);
    while(j<=k){
        if(v[j] == 0){
            swap(v[i], v[j]);i++;j++;
        }else if(v[j] == 1){
            j++;
        }else{
            swap(v[j], v[k]);k--;
        }
    }
}

void sort_123_(vector<int> &v){
    unordered_map<int,int> m;
    for(auto &i:v){
        m[i]++;
    }
    int i(0),p(0);
    for(int j=0;j<=2;j++){
        i=0;
        while(i<m[j]){
            v[p] = j;i++;p++;
        }
    }
}

int main(){
    vector<int> v = {0,1,0,1,2,1,2,1,0,1,2,0,0,0,1,1,2,2,2,1,2,1,0};
    sort_123_(v);
    for(int &i:v){
        cout << i << endl;
    }
    return 0;
}