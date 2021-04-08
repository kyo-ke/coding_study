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

void swap(int &i, int &j){
    i ^= j;j ^= i; i ^= j; 
}

void merge(vector<int> &a, vector<int> &b){
    int pa(0), pb(0);
    while(pa + pb < a.size()){
        if(pb < b.size()){
            if(a[pa] < b[pb]){
                pa++;
            }else{
                pb++;
            }
        }else{
            pa++;
        }
    }
    int i(0);
    while(i < pb){
        swap(a[pa], b[i]);
        i++;pa++;
    }
    sort(a.begin(), a.end());sort(b.begin(), b.end());
}



int main(){
    vector<int> a{1,2,3,5,5,6,7,10}, b{4,5,6,8,10,11};
    merge(a,b);
    for(int &i:a){
        cout << i << endl;
    }
    for(int &i:b){
        cout << i << endl;
    }
}