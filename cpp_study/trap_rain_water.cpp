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

int trap_water(vector<int> v){
    vector<int> left_max(v.size()), right_max(v.size());
    int m(0),i(0);
    while(i < v.size()){
        m = max(m, v[i]);left_max[i]=m;i++;
    }
    m = 0;i = v.size()-1;
    while(i >= 0){
        m = max(m, v[i]);right_max[i]=m;i--;
    }
    m=0;i=1;
    while(i < v.size()-1){
        m += min(left_max[i], right_max[i])-v[i];i++;
    }
    return m;
}

int trap_water2(vector<int> v){
    int l(0),r(v.size()-1),l_max(0), r_max(0),ans(0);
    while(l <= r){
        if(v[l] >= v[r]){
            l_max = max(v[l], l_max);ans += l_max-v[l];l++;
        }else{
            r_max = max(r_max, v[r]);ans += r_max-v[r];r--;
        }
    }
    return ans;
}

int main(){
    vector<int> blocks{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; //6
    //vector<int> blocks{3, 0, 2, 0, 4};//7
    cout << trap_water2(blocks) << endl;
    return 0;
}