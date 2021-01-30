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

int max_profit(vector<int> &prices){
    int ans(INT_MIN),m(prices[0]);
    for(int i=0;i<prices.size();i++){
        ans = max(ans,prices[i]-m);
        m = min(m,prices[i]);
    }
    return ans;
}

int max_profit2(vector<int> &prices){
    int buy(0), sell, profit(0);
    while(prices.size()-1 > buy){
        while(prices[buy] >= prices[buy+1]){
            buy++;
            if(buy == prices.size()-1){
                return profit;
            }
        }
        sell = buy+1;
        if(sell == prices.size()-1){
            return profit + prices[sell] - prices[buy];
        }
        while(prices[sell] <= prices[sell+1]){
            sell++;
            if(sell == prices.size()-1){
                break;
            }
        }
        profit += prices[sell] - prices[buy];
        buy = sell + 1;
    }
    return profit;
}

int main(){

    vector<int> v{100, 180, 260, 310, 40, 535, 695};
    //vector<int> v{40, 100, 180, 260, 310, 40, 535, 695,100};
    //vector<int> v{40,30,20,10};
    cout << max_profit2(v) << endl;
    return 0;
}