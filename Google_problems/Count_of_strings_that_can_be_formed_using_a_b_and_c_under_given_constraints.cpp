#include <iostream>

using namespace std;

//all a
//one b or c
//one b one c
//two c
//one b two c
int count_string(int n){
    int ans(0);
    //all a
    ans++;
    //one b, one c
    ans += n*2;
    //one b and one c
    ans += n*(n-1);
    //two c
    ans += n*(n-1)/2;
    //two c and one b
    ans += n*(n-1)*(n-2)/2;
    return ans;
}

void helper(int count,int countc, int countb, int &ans){
    if(count == 0){
        ans += 1;
    }else{
        helper(count-1, countc, countb,ans);
        if(countc > 0){
            helper(count-1, countc-1, countb, ans);
        }
        if(countb > 0){
            helper(count-1, countc, countb-1, ans);
        }
    }
}


int count_string2(int n){
    int ans(0);
    helper(n, 2,1,ans);
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << count_string2(n) << endl;
    return 0;
}
