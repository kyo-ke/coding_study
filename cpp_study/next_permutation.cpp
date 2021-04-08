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

void swap(int &i,int &j){
    int temp;temp=i;i=j;j=temp;
}

void reverse(vector<int> &v, int l,int r){
    while(l < r){
        swap(v[l], v[r]);l++;r--;
    }
}

void next_permutation(vector<int> &v){
    int i(v.size()-1),j(v.size()-1);
    while(v[i] <= v[i-1]){
        i--;
        if(i == 0){
            break;
        }
    }
    i--;
    if(i != 0){
        while(v[j] < v[i]){
            j--;
        }
        swap(v[i], v[j]);
        reverse(v, i+1, v.size()-1);
    }
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8};
    next_permutation(v);//next_permutation(v);
    for(int &i: v){
        cout << i << endl;
    }
    return 0;
}