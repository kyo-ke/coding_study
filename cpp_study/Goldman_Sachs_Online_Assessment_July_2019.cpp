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

string encryption(string s, string num){
    string enc = "";
    int i(0),j(0);
    while(i < num.size()){
        while(j < num[i]-'0'){
            enc += s[i];j++;
        }
        j = 0;i++;
    }
    enc += s.substr(i);
    return enc;
}

string decryption(string s, string num){
    string dec("");
    int i(0),j(0);
    while(i < num.size()){
        dec += s[j];
        j += (num[i] - '0');
        i++;
    }
    dec += s[j];
    dec += s.substr(j+1);
    return dec;
}

int main(){
    string s,num;
    cin >> s >> num;
    cout << decryption(s, num) << endl;
    return 0;
}