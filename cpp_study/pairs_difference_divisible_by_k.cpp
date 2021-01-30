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


int divisible_pairs(vector<int> &v, int k){
    for(int &i:v){
        i %= k;
    }
    vector<int> m(k);
    int ans(0);
    for(int &i:v)m[i]++;
    for(int i = 1;i<k;i++)ans += m[i]*(m[i]-1)/2;
    return ans;
}

int main(){
    vector<int> v = {3,7,11};
    cout << divisible_pairs(v,4) << endl;
    return 0;
}