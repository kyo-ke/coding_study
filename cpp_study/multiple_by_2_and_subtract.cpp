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

int convert(int val, int target){
    if(val == target ){
        return 0;
    }else{
        vector<bool> dp(20000+1);
        queue<int> q;
        int count(0), q_size, temp;
        q.push(val);dp[val] = true;
        while(!q.empty()){
            count++;q_size = q.size();
            for(int i=0;i<q_size;i++){
                temp = q.front();q.pop();
                if(temp*2 == target){
                    return count;
                }else{
                    if(temp*2 < target * 2){
                        if(!dp[temp*2]){
                            dp[2*temp] = true;
                            q.push(2*temp);
                        }
                    }
                }
                if(temp-1 == target){
                    return count;
                }else{
                    if(0 <= temp-1){
                        if(!dp[temp-1]){
                            dp[temp-1] = true;
                            q.push(temp-1);
                        }
                    }
                }
            }
        }
        return count;
    }
}

int main(){
    cout << convert(2,5) << endl;
    return 0;
}