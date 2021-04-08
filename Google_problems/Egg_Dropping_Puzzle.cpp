#include<iostream>
#include<vector>

using namespace std;

int g(int n){
    return n;
}

//min_k(max(f(n-k), f(k-1)))
int count_drop(int num,vector<int> &dp){
    if(num == 0){
        return 0;
    }else if(num == 1){
        return 1;
    }else if(dp[num] != 0){
        return dp[num];
    }else{
        int m(INT_MAX);
        for(int i=1;i<=num; i++){
            m = min(m, max(count_drop(num - i, dp), g(i-1)));
        }
        return dp[num] = m + 1;
    }
}

int wrapper(int num){
    vector<int> dp;
    dp.resize(num+1);
    return count_drop(num, dp);
}

int main(){
    int i= 10;
    cout << "number of trial is " << wrapper(i) << endl;
    return 0;
}
