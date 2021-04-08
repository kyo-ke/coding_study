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

string longest_palindrome(string s){
    vector<vector<bool>> dp(s.size());
    for(auto &v:dp){
        v.resize(s.size());
    }
    for(int i=0;i<s.size();i++){
        dp[i][i] = true;
    }
    int i=0,l, r;
    while(i+1<s.size()){
        dp[i][i+1] = (s[i] == s[i+1]);
        if(dp[i][i+1]){
            l=i;r=i+1;
        }
        i++;
    }
    for(i=s.size()-1;i>=0;i--){
        for(int j=i+2;j < s.size();j++){
            if(s[i]==s[j] && dp[i+1][j-1]){
                dp[i][j] = true;
                if(r-l < j-i){
                    l = i;r = j;
                }
            }
        }
    }
    return string(s.begin()+l, s.begin()+r+1);
}

int main(){
    string s = "forgeeksskeegfor";
    cout << longest_palindrome(s) << endl;
    return 0;
}