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


int count_mistake(vector<string> &products, vector<float> &prices, vector<string> &s_products,vector<float> &s_prices){
    unordered_map<string, float> m;
    int count (0);
    for(int i=0;i<products.size();i++){
        m[products[i]] = prices[i];
    }
    for(int i=0;i<s_products.size();i++){
        if(m[s_products[i]] != s_prices[i]){
            count++;
        }
    }
    return count;
}

int main() 
{ 
    vector<string> products = {"eggs","milk","cheese"}, sell_products{"eggs","eggs","milk","cheese"};
    vector<float> prices {2.89,3.29,5.79}, sell_prices{2.89,2.99,3.29,5.97};
    cout << count_mistake(products, prices, sell_products, sell_prices) << endl;
    return 0;
}