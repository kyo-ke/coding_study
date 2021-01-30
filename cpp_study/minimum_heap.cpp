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


struct min_heap{
    vector<int> arr;
    int get_left(int i){
        int l = (i+1)*2-1;
        if(l < arr.size()){
            return l;
        }else{
            return -1;
        }
    }    
    int get_right(int i){
        int r = (i+1)*2;
        if(r < arr.size()){
            return r;
        }else{
            return -1;
        }
    }
    void down(int i){
        int l(get_left(i)),r(get_right(i));
        if(l != -1){
            if(arr[i] > arr[l]){
                swap(arr[i], arr[l]);down(l);
            }else if(r != -1){
                if(arr[i] > arr[r]){
                    swap(arr[i], arr[r]);down(r);
                }
            }
        }
    }
    void up(int i){
        if(i > 0){
            if(arr[(i-1)/2] > arr[i]){
                swap(arr[(i-1)/2], arr[i]);up((i-1)/2);
            }
        }
    }
    void insert(int i){
        arr.push_back(i);
        up(arr.size()-1);
    }
    int top(){return arr[0];}
    
    void pop(){
        swap(arr[0], arr[arr.size()-1]);
        arr.pop_back();
        down(0);
    }
};

void swap(int a, int b){
    int temp(a);a=b;b=a;
}


int main(){
    min_heap mh;
    mh.insert(1);
    cout << mh.top() << endl;
    mh.insert(2);
    cout << mh.top() << endl;
    mh.insert(-1);
    cout << mh.top() << endl;
    mh.pop();
    cout << mh.top() << endl;
    mh.pop();
    cout << mh.top() << endl;
    return 0;
}