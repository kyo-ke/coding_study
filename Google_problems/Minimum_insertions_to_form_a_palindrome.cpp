#include<iostream>
#include<string>
#include <cassert>
#include <algorithm>
#include <functional>
using namespace std;

int lcs(string &a, int ap, string &b, int bp, int num){
    if(ap == a.size()){
        return num;
    }else if(bp == b.size()){
        return num;
    }else{
        if(a[ap] == b[bp]){
            return lcs(a, ap+1,b,bp+1,num+1);
        }else{
            return max(lcs(a,ap+1,b,bp,num),lcs(a,ap,b,bp+1,num));
        }
    }
}

int lcs_helper(int mid, string &s, int l, int r, int num){
    if(l == mid){
        return num;
    }else if(r == s.size()){
        return num;
    }else{
        if(s[l] == s[r]){
            return lcs_helper(mid, s, l+1, r+1, num+1);
        }else{
            return max(lcs_helper(mid, s, l+1, r, num), lcs_helper(mid, s, l, r+1, num));
        }
    }
}

int lcs_inplace(string &s, int mid){
    return lcs_helper(mid, s, 0, mid, 0);
}
//two case, how to handle center character
//one pointer in lcs inplace should run from tail and another should run from head
int form_palindrome(string s){
    int ans(INT_MAX);
    for(int i=0; i < s.size()-1;i++){
        ans = min(ans, (int)s.size() - lcs_inplace(s, i)*2);
    }
    return ans;
}

int main(){
  //  string a("hello"), b("meltllllllllllllo");
  //  cout << lcs(a,0,b,0,0) << endl;
    string a("ab");
    cout << form_palindrome(a) << endl;
    return 0;
}
