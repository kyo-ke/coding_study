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


int local_minimum(vector<int> &v){
    int l(0),  r(v.size()), mid;
    while(l <= r){
        mid = (l+r)/2;
        if(0 == mid){
            if(v[mid] < v[mid+1]){
                return mid;
            }else{
                return 1;
            }
        }else if(mid == v.size()-1){
            return mid;
        }else{
            if(v[mid-1] > v[mid] && v[mid] < v[mid+1]){
                return mid;
            }else if(v[mid] > v[mid-1]){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> v{23, 8, 15, 2, 3};
    //cout << local_minimum(v) << endl;
    int i=5;
    while(i>=0){
        i--;
        if(i >=0 && v[i]){
            cout << v[i] << endl;
        }else{
            break;
        }
    }
    return 0;
}