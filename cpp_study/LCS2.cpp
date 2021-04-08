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


//dp[i][j] = max(dp[i-1][j], dp[])

string back_track(string &a, string &b, vector<vector<int>> &dp){
    string ans ("");
    int i(a.size()-1),j(b.size()-1);
    while(i > 0 && j > 0){
        if(dp[i][j] == dp[i-1][j]){
            i--;
        }else if(dp[i][j] == dp[i][j-1]){
            j--;
        }else{
            ans += a[i];i--;j--;
        }
    }
    if(dp[i][j] != 0){
        int k(0);
        if(i != 0){
            while(dp[k][0] == 0){
                k++;
            }
            ans += a[k];
        }else
        {
            while(dp[0][k] == 0){
                k++;
            }
            ans += b[k];
        }
        
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string LCS(string &a, string &b){
    if(a.size() ==0 | b.size() == 0){
        return "";
    }else{
        vector<vector<int>> dp(a.size());
        for(auto &v:dp){
            v.resize(b.size());
        }
        int i(0);
        while(a[i] != b[0]){
            dp[i][0] = 0;i++;
            if(i == a.size()){
                break;
            }
        }
        while(i < a.size()){
            dp[i][0] = 1;i++;
        }
        i = 0;
        while(b[i] != a[0]){
            dp[0][i] = 0;i++;
            if(i == b.size()){
                break;
            }
        }
        while(i < b.size()){
            dp[0][i] = 1;i++;
        }
        for(i=1;i<a.size();i++){
            for(int j=1;j<b.size();j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(a[i] == b[j]){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }
            }
        }
        return back_track(a,b,dp);
    }
}


int main(){
    string a("abcdef"),b("aeeeeecf");
    cout << LCS(a,b) << endl;
    return 0;
}