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


int missing_number(vector<int> &v){
    int m,l(0), r(v.size()-1), mid;
    while(l <= r){
        mid = (l+r)/2;m = v[l];
        if(mid == 0){
            return v[1]-1;
        }
        if(v[mid]-v[mid-1] == 2){
            return v[mid]-1;
        }else if(mid - l == v[mid]-v[l]){
            l = mid + 1;
        }else{
            r = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> v{2,4,5,6,7,8,9,10};
    cout << missing_number(v) << endl;
    return 0;
}