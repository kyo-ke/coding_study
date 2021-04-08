#include<iostream>
#include<vector>
#include<list>
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


int minimum_steps(int sx, int sy, int ex, int ey){
    if(sx == ex && sy == ey){
        return 0;
    }
    vector<vector<bool>> dp(8);
    vector<vector<int>> delta{{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,-1},{-2,1},{2,-1}};
    for(int i=0;i<dp.size();i++){
        dp[i].resize(8);
    }
    dp[sx][sy] = true;
    queue<pair<int,int>> q;
    pair<int,int> temp;
    int count(0), q_size,j,tempx, tempy;
    q.push(make_pair(sx,sy));
    while(!q.empty()){
        q_size = q.size();j=0;count ++;
        while(j<q_size){
            temp = q.front();q.pop();
            for(auto &d:delta){
                tempx = temp.first + d[0];tempy =  temp.second + d[1];
                if(min(tempx, tempy) >= 0 && max(tempx, tempy) < 8){
                    if(!dp[tempx][tempy]){
                        if(tempx == ex && tempy == ey){
                            return count;
                        }else{
                            dp[tempx][tempy]=true;
                            q.push(make_pair(tempx,tempy));
                        }
                    }
                }
            }
            j++;
        }
    }
    return -1;
}

int min_steps_(int sx,int sy,int ex, int ey){
    return minimum_steps(sx-1,sy-1,ex-1,ey-1);
}
int main(){
    int sx(2),sy(4),ex(6),ey(4);
    cout << min_steps_(sx,sy,ex,ey) << endl;
    return 0;
}