#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool validate(string target, string word){
    int i(0),j(0);
    while(target.size() > i && word.size() > j){
        if(target[i] == word[j]){
            j++;i++;
        }else{
            j++;
        }
    }
    return i == target.size();
}

string find_largest(vector<string> strs, string word){
    string ans = "";
    for(auto &s:strs){
        if(validate(s,word)){
            if(ans.size() < s.size()){
                ans = s;
            }
        }
    }
    return ans;
}

int main(){
    vector<string> strs = {"pintu", "geeksfor", "geeksgeeks", 
                                        " forgeek"} ;
    string word("geeksforgeeks");
    cout << find_largest(strs, word) << endl;
    return 0;
}
