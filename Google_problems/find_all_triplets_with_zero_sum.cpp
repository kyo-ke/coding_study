#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> find_triplets(vector<int> v){
    vector<vector<int>> ans;
    vector<int> temp;
    sort(v.begin(), v.end() );
    int h(0),m,t;
    while(h < v.size()-2){
        if(v[h] >= 0){
            break;
        }else{
            m=h+1;t=v.size()-1;
            while(m < t){
                if(v[m] + v[t] + v[h] == 0){
                    temp.push_back(v[h]);
                    temp.push_back(v[m]);
                    temp.push_back(v[t]);
                    ans.push_back(temp);
                    temp.clear();
                    break;
                }else if(v[m] + v[t] + v[h] > 0){
                    t--;
                }else{
                    m++;
                }
            }
            h++;
        }
    }
    return ans;
}

int main(){
    //value of vec needs to be distinct
    vector<int> vec{0, -1, 2, -3, 1};
    auto ans = find_triplets(vec);
    for(auto &v:ans){
        for(int &i:v){
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}

