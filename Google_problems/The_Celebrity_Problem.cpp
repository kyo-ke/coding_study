#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int find_celebrity(vector<vector<int>> mat){
   //make queue for candidate
    queue<int> candidates;
    for(int i=0;i<mat[0].size();i++){
        if(mat[0][i] == 1){
            candidates.push(i);
        }
    }
    if(candidates.size() == 0){
        return 0;
    }
    int candidate, candidate_, count;
    while(candidates.size() > 0){
        candidate = candidates.front();candidates.pop();
        count = candidates.size();
        while(count > 0){
            candidate_ = candidates.front();candidates.pop();
            if(mat[candidate][candidate_] == 1){
                candidate = candidate_;
                break;
            }
            count--;
        }
    }
    for(int i=0;i<mat[0].size();i++){
        if(mat[candidate][i] == 1){
            return -1;
        }
    }
    return candidate;
}

int main(){
   // vector<vector<int>> mat 
   // { {0, 0, 1, 0},
   //   {0, 0, 1, 0},
   //   {0, 0, 0, 0},
   //   {0, 0, 1, 0} };

    vector<vector<int>> mat{ {0, 0, 1, 0},
           {0, 0, 1, 0},
           {0, 1, 0, 0},
           {0, 0, 1, 0} };
    cout << "celebrity is " << find_celebrity(mat) << endl;

    return 0;
}
