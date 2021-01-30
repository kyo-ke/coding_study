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


int minimum_platform(vector<int> &arr, vector<int> &dep){
    int a(0),d(0), count(0), ans(INT_MIN);
    while(a < arr.size()){
        if(arr[a] < dep[d]){
            a++;count++;
            ans = max(ans,count);
        }else if (arr[a] == dep[d]){
            a++;d++;
        }else{
            count--;d++;
        }
    }
    return ans;∑
}

int main(){
    //arr and dep should be sorted
    vector<int> arr = { 900, 940, 950, 1100, 1500, 1800 };
    vector<int> dep = { 910, 1200, 1120, 1130, 1900, 2000 };
    cout << minimum_platform(arr, dep) << endl;
    return 0;
}