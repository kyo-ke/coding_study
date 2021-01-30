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


int knapsack_rec(vector<int> &v, vector<int> &w, int W, int i){
    if(i >= v.size()){
        return 0;
    }else if(w[i] <= W){
        return max(knapsack_rec(v,w,W-w[i],i+1)+v[i], knapsack_rec(v,w,W,i+1));
    }else{
        return knapsack_rec(v,w,W,i+1);
    }
}

int knapsack1(vector<int> &v, vector<int> &w,int W){
    return knapsack_rec(v,w,W,0);
}

int knapsack2(vector<int> &v, vector<int> &w, int W){
    vector<vector<int>> dp(v.size());
    for(auto &dpv:dp){
        dpv.resize(W+1);
    }
    for(int i=0; i<=W;i++){
        if(i >= w[0]){
            dp[0][i] = v[0];
        }else{
            dp[0][i] = 0;
        }
    }
    for(int j=1;j<v.size();j++){
        for(int i=1;i<=W; i++){
            if(i-w[j] >= 0){
                dp[j][i] = max(dp[j-1][i-w[j]] + v[j],dp[j-1][i]);
            }else{
                dp[j][i] = dp[j-1][i];
            }
        }
    }
    return dp[v.size()-1][W];
}


int main(){
    vector<int> value{60,100,120};
    vector<int> weight{10,20,30};
    int W(50);
    cout << knapsack2(value, weight, W) << endl;
    return 0;
}