#include<iostream>
#include<vector>

using namespace std;
//suppose there is no zero in given array
vector<pair<int,int>> find_subarray(vector<int> &nums, int &target){
    //deal 0 differently
    //target > 0
    vector<pair<int,int>> ans;
    int head(0), tail(0), s(0);
    while(tail < nums.size()){
        while(s < target){
            s += nums[tail++];
            if(tail == nums.size()){
                break;
            }
        }
        while(s > target){
            s -= nums[head++];
        }
        if(s == target){
            ans.push_back(make_pair(head, tail-1));
            s-=nums[head++];
        }
    }
    return ans;
}


//utility function for printing vector
void print_vec(vector<pair<int,int>> &v){
    for(auto &p:v){
        cout << "start: " << p.first << ", end: " << p.second << endl;
    }
}

int main(){
    vector<int> nums{1, 4, 20, 3, 10, 5};
    int target = 33;
    vector<pair<int,int>> ans;
    ans = find_subarray(nums, target);
    print_vec(ans);
    return 0;
}
