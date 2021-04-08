#include<iostream>
#include<vector>

using namespace std;

bool is_jumping(int num){
    int dig1(num%10), dig2(-1);
    num/=10;
    while(num != 0){
        dig2 = dig1;
        dig1 = num%10;
        num /= 10;
        if(abs(dig2-dig1) != 1){
            return false;
        }
    }
    return true;
}

vector<int> jumps(int n){
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(is_jumping(i)){
            ans.push_back(i);
        }
    }
    return ans;
}

void helper(int n, int dig, vector<int> &ans, int &target){
    cout << "n : " << n << ", dig : " << dig << endl;
    if(n <= target){
        ans.push_back(n);
        int last_num = n/dig;
        dig *= 10;
        if(last_num > 1){
            helper(n + (last_num-1)*dig,dig,ans, target);
        }
        if(last_num < 9){
            helper(n + (last_num+1)*dig,dig,ans, target);
        }
    }
}


vector<int> jumps2(int n){
    vector<int> ans;
    for(int i=1;i<=9;i++){
        helper(i,1,ans, n);
    }
    return ans;
}

int main(){
    int n(105);
    vector<int> ans(jumps2(n));
    for(int &i:ans){
        cout << i << endl;
    }
    return 0;
}
