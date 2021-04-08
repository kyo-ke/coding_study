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

void swap(int &i,int &j){
    int temp;temp=i;i=j;j=temp;
}

int partition(vector<int> &v, int l, int r){
    if(l < r){
        int pivot(v[l]),j(r), i(l+1);
        while(i <= j){
            if(v[i] >= pivot){
                swap(v[i],v[j]);j--;
            }else{
                i++;
            }
        }
        swap(v[l],v[j]);
        return j;
    }
    return -1;
}

void quick_sort_helper(vector<int> &v,int l, int r){
    if(l < r){
        int mid(partition(v, l, r));
        quick_sort_helper(v, l, mid-1);
        quick_sort_helper(v, mid+1, r);
    }
}

void quick_sort(vector<int> &v){
    quick_sort_helper(v, 0, v.size()-1);
}
int main(){
    vector<int> v={5,4,3,4,5,6,7,8,1,2,3,4,1,5};
    quick_sort(v);
    for(int &i:v){
        cout << i;
    }
    cout << endl;
}