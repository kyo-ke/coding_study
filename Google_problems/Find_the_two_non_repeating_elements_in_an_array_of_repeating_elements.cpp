#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> find_nonrepeat(vector<int> &v){
    unordered_map<int,int> m;
    vector<int> ans;
    for(int i:v){
        m[i]++;
    }
    for(auto it=m.begin();it != m.end();it++){
        if(it->second == 1){
            ans.push_back(it->first);
        }
    }
    return ans;
}

vector<int> find_nonrepeat2(vector<int> &v){
    sort(v.begin(), v.end());
    int i(0);
    vector<int> ans;
    while(i < v.size()-1){
        if(v[i] == v[i+1]){
            i+=2;
        }else{
            ans.push_back(v[i++]);
        }
    }
    if(ans.size() < 2){
        ans.push_back(v[i]);
    }
    return ans;
}

vector<int> find_nonrepeating3(vector<int> v){


}

int main(){
    vector<int> v = {2, 3, 9, 11, 2, 3, 11, 7};
    vector<int> ans;
    //ans = find_nonrepeat(v);
    ans = find_nonrepeat2(v);
    cout << ans[0] << ", "<< ans[1] << endl;
    return 0;
}
