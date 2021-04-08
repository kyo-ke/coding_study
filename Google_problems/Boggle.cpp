#include<iostream>
#include<vector>
#include<string>
using namespace std;


bool helper(int x, int y, string word, vector<vector<bool>> history, vector<vector<char>> &boggle){
    if(min(x,y) < 0 || y >= boggle.size() || x >= boggle[0].size()){
        return false;
    }else if(history[y][x]){
        return false;
    }else if(word[0] != boggle[y][x]){
        return false;
    }else{
        if(word.size() == 1){
            return true;
        }else{
            history[y][x] = true;
            bool ans = false;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(j != 0 || i!=0){
                        ans |= helper(x+i,y+j,word.substr(1), history, boggle);
                    }
                }
            }
            return ans;
        }
    }
}

vector<string> find_words(vector<string> dictionary, vector<vector<char>> boggle){
    vector<string> ans;
    bool flag;
    vector<vector<bool>> history;
    history.resize(boggle.size());
    for(auto &vec: history){
        vec.resize(boggle[0].size());
    }
    for(auto word: dictionary){
        flag = false;
        for(int x=0;x<boggle[0].size();x++){
            for(int y=0;y<boggle.size();y++){
                flag |= helper(x,y,word,history, boggle);
            }
        }
        if(flag){
            ans.push_back(word);
        }
    }
    return ans;
}



int main(){
   // vector<string> dictionary{"GEEKS", "FOR", "QUIZ", "GO"};
   // vector<vector<char>> boggle{{'G', 'I', 'Z'},
   //                             {'U', 'E', 'K'},
   //                             {'Q', 'S', 'E'}};
    vector<string> dictionary{"GEEKS", "ABCFIHGDE"};
    vector<vector<char>> boggle{{'A', 'B', 'C'},
                                {'D', 'E', 'F'},
                                {'G', 'H', 'I'}};
    vector<string> ans = find_words(dictionary, boggle);
    for(auto word: ans)
    {
        cout << word << endl;
    }
    return 0;
}
