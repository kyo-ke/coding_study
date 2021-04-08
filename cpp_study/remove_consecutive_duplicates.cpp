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

string  remove_consecutive(string s){
    string ans = "";
    int i(0),j;
    while(i < s.size()){
        j = i;
        while(s[j] == s[i]){
            j++;
            if(j == s.size())break;
        }
        ans += s[i];
        i = j;
    }
    return ans;
}

int main(){
    //string s("aaaaaaaaaaabbbbbbbb");
    string s("geeksforgeeks");
    cout << remove_consecutive(s) << endl;
}