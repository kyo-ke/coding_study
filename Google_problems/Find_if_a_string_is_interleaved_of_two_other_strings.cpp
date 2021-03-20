#include<iostream>
#include<string>


using namespace std;

bool helper(string a, int a_num, string b, int b_num, string c, int c_num){
    if(c_num == c.size()){
        return true;
    }else{
        bool ans;
        if(a[a_num] == c[c_num]){
            ans |= helper(a, a_num+1, b,b_num, c, c_num+1);
        }
        if(b[b_num] == c[c_num]){
            ans |= helper(a, a_num, b, b_num+1, c, c_num+1);
        }
        return ans;
    }
}

bool check(string a, string b, string c){
    if(a.size() + b.size() != c.size()){
        return false;
    }else{
        return helper(a,0,b,0,c,0);
    }
}


int main(){
    string a("XXY"), b("XXZ"), c("XXXXZY");
    //string a("x"), b("yx"), c("xxy");
    if(check(a,b,c)){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }
    return 0;
}
