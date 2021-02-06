#include <iostream>
#include <vector>
#include <string>

using namespace std;

void helper(string s, int i, vector<string> &ans){
    if(i == s.size()){
        ans.push_back(s);
    }else if(s[i] != '?'){
        helper(s, i+1, ans);
    }else{
        s[i] = '0';
        helper(s,i+1, ans);
        s[i] = '1';
        helper(s,i+1, ans);
    }
}

vector<string> generate_binary_string(string s){
    vector<string> ans;
    helper(s, 0, ans);
    return ans;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = generate_binary_string(s);
    for(string &s_: ans){
        cout << s_ << endl;
    }
    return 0;
}
