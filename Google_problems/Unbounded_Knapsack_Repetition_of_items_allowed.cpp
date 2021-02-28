#include<iostream>
#include<vector>

using namespace std;

vector<int> memo;

void helper(int &ans, int S, int W, vector<int> &w, vector<int> &val){
    ans = max(S, ans);
    for(int i=0;i<w.size();i++){
        if(w[i] <= W){
            if(memo[W-w[i]] < S+val[i]){
                helper(ans, S+val[i], W-w[i], w,val);
                memo[W-w[i]] = S+val[i];
            }
        }
    }
}

int knapsack(int W, vector<int> &w, vector<int> &val){
    int ans(0);
    helper(ans,0,W,w,val);
    return ans;
}

int main(){
    int W(100);
    memo.resize(W+1);
    vector<int> val{10, 40, 50, 70}, w{1, 3, 4, 5};
    cout << "maximum sum of value is : " << knapsack(W,w,val) << endl;
    return 0;
}
