#include<iostream>
#include<string>

using namespace std;

bool is_metastring(string s1, string s2){
    if(s1.size() != s2.size()){
        return false;
    }else if(s1 == s2){
        return true;
    }else{
        int f(-1),s(-1),p(0);
        while(p < s1.size()){
            while(s1[p] == s2[p]){
                p++;
                if(p == s1.size()){
                    break;
                }
            }
            if(f == -1){
                f = p;
            }else if(s == -1){
                s = p;
            }else{
                break;
            }
            p++;
        }
        return p == s1.size() && s1[f] == s2[s] && s1[s] == s2[f];
    }
}

int main(){
    //string s1("geeks"), s2("keegs");
    string s1("geekss"), s2("keegs");
    if(is_metastring(s1, s2)){
        cout << s1 << " and " << s2 << " are metastring" << endl;
    }else{
        cout << "these are not meta string" << endl;
    }
    return 0;
}
