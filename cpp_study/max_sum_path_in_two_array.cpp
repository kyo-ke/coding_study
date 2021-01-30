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


int max_path(vector<int> &v1, vector<int> &v2){
    unordered_map<int,bool> m;
    for(int &i:v1){
        m[i] = true;
    }
    vector<int> nums;
    nums.reserve(min(v1.size(), v2.size()));
    for(int &i:v2){
        if(m.find(i) != m.end()){
            nums.push_back(i);
        }
    }
    int i(0),j(0),k(0);
    int ans(0), s1(0), s2(0);
    while(k < nums.size()){
        while(v1[i] != nums[k]){
            s1 += v1[i];i++;
        }
        while(v2[j] != nums[k]){
            s2 += v2[j];j++;
        }
        ans += max(s1, s2) + nums[k];i++;j++;k++;
        s1 = 0;s2 = 0;
    }
    while(i < v1.size()){
        s1 += v1[i++];
    }
    while(j < v2.size()){
        s2 += v2[j++];
    }
    ans += max(s1,s2);
    return ans;
}

int main(){
    vector<int> v1{2, 3, 7, 10, 12, 15, 30, 34, 50,51,52,53}, v2 {1, 5, 7, 8, 10, 15, 16, 19, 50, 200};
    cout << max_path(v1, v2) << endl;
    return 0;
}