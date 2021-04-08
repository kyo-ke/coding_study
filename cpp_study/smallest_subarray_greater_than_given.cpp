

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

int smallest_subarray(vector<int> &v, int val){
    int st(0),ed(0),s(0),ans(INT_MAX);
    while(ed < v.size()){
        while(s <= val){
            if(ed >= v.size()){
                return ans;
            }
            s += v[ed];
            ed++;
        }
        while(s-v[st] > val){
            s-=v[st];
            st++;
        }
        ans = min(ans, ed - st);
        s-=v[st];st++;
    }
    return ans;
}

int main(){
    vector<int> v = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    cout << smallest_subarray(v, 280) << endl;
    return 0;
}