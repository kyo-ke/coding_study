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



int LCS(string s1, string s2){
    vector<vector<int>> dp(s1.size());
    for(auto &v: dp){
        v.resize(s2.size());
    }
    int i(0),j(0);
    if(s1[i] == s2[j])dp[i][j] = 1;
    j = 1;
    while(j < s2.size()){
        dp[0][j] = dp[0][j-1] | (s1[0] == s2[j]);
        j++;
    }
    j = 0;i=1;
    while(i < s1.size()){
        dp[i][j] = dp[i-1][j] | (s2[j] == s1[i]);
        i++;
    }    for(i = 1;i<s1.size();i++){
        for(j = 1;j<s2.size();j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s1[i] == s2[j]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }
    return dp[s1.size()-1][s2.size()-1];
}

int main(){
    string s1("abcdefg"), s2("anmkhbnmjc");
    cout << LCS(s1, s2) << endl;
}