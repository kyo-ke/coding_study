#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<stack>
#include<random>
#include<iterator>
#include <algorithm>
#include <functional>
#include <cassert>
#include <iomanip>
#include<unordered_map>
#include<bitset>
using namespace std;



float find_median(vector<int> &v1, vector<int> &v2){
    vector<int> rv, sv;
    if(v1.size() > v2.size()){
        rv = v1;sv = v2;
    }else{
        rv = v2;sv = v1;
    }
    int l(0),r(sv.size()), mid,mid2, S = v1.size() + v2.size();
    if(S % 2 == 1){
        while(1){
            mid = l/2 + r/2 + l%2 + r%2;
            mid2 = S/2 - mid;
            if(mid == 0){
                if(sv[mid] > rv[mid2-1]){
                    return (float)min(sv[mid], rv[mid2]);
                }else
                {
                    return (float)min(sv[mid+1], rv[mid2-1]);
                }
            }else if(mid == sv.size()){
                return (float)rv[mid2];
            }else if(sv[mid-1] < rv[mid2] && sv[mid] > rv[mid2-1]){
                return (float)min(sv[mid], rv[mid2]);
            }else if(sv[mid-1] > rv[mid2]){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
    }else{
        while(1){
            mid = l/2 + r/2 + l%2 + r%2;
            mid2 = S/2 - mid;
            cout << "l : " << mid << " , r : " << mid2 << endl;
            if(mid == 0){
                if(sv[mid] > rv[mid2-1]){
                    return (float)(min(sv[mid], rv[mid2])+rv[mid2-1])/2;
                }else
                {
                    return (float)(min(sv[mid+1], rv[mid2-1]) + max(sv[mid], rv[mid2-2]))/2;
                }
            }else if(mid == sv.size()){
                return (float)(max(rv[mid2-1], sv[mid]) + rv[mid2])/2;
            }else if(sv[mid-1] <= rv[mid2] && sv[mid] >= rv[mid2-1]){
                return (float)(min(sv[mid], rv[mid2])+max(sv[mid-1], rv[mid2-1]))/2;
            }else if(sv[mid-1] > rv[mid2] | sv[mid] < rv[mid2-1]){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
    }
    return 0;
    
}

int main(){
    vector<int> v1 = {1,2,3,4,5,6,10,11,15,17,20};
    vector<int> v2 = {1,2,3,4,5,6,10,11,15,17,20};
    cout << find_median(v1, v2) << endl;
    return 0;
}
