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

bool wildcard_matching(string &s, string &p){
    if(s == p){
        return true;
    }else if(p.size() == 0){
        return false;
    }else{
        vector<vector<bool>> dp(p.size());
        for(auto &v:dp)v.resize(s.size());
        if(p[0] == '*'){
            for(int k=0;k<s.size();k++)dp[0][k]=true;
        }else if(p[0] == '?' | p[0] == s[0]){
            for(int k=0;k<s.size();k++)dp[0][k]=false;dp[0][0] = true;
        }else{
            for(int k=0;k<s.size();k++)dp[0][k]=false;
        }
        int j=1;
        while(p[j] == '*' && p[0] == '*'){
            dp[j][0] = true;
            j++;
            if(j == p.size()){
                break;
            }
        }
        while(j < p.size()){
            dp[j][0] = false;
            j++;
        }
        for(int i=1;i<p.size();i++){
            if(p[i] == '*'){
                j = 1;
                while(!dp[i-1][j]){
                    j++;
                    if(j == s.size()){
                        break;
                    }
                }
                while(j < s.size()){
                    dp[i][j] = true;
                    j++;
                }
            }else{
                for(j = 1;j<s.size();j++){
                    if(dp[i-1][j-1] && (p[i] == '?' | p[i] == s[j])){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        cout << dp[0][0] << endl;
        return dp[p.size()-1][s.size()-1];
    }
}


int main(){
    string p = "ab?c*j*l";
    string s = "abecdfhgjkllllll";
    if(wildcard_matching(s,p)){
        cout << "match" << endl;
    }else{
        cout << "not match" << endl;
    }
    return 0;
}
