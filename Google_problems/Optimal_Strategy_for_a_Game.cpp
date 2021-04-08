#include<iostream>
#include<vector>
using namespace std;

int optimal(vector<int> &v, int h, int t){
    if(t-h == 1){
        return max(v[h], v[t]);
    }else{
        int s(0);
        for(int i=h;i <= t; i++){
            s += v[i];
        }
        int l, r;
        l = optimal(v, h+1, t);r = optimal(v, h, t-1);
        return s - min(l,r);
    }
}

int wrapper(vector<int> v){
    return optimal(v, 0, v.size()-1);
}

int main(){
    //vector<int> v{5, 3, 7, 10};
    vector<int> v{8, 15, 3, 7};
    cout << wrapper(v) << endl;
    return 0;
}
