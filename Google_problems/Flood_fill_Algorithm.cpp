#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

void helper(vector<vector<int>> &screen, int x, int y, int c, int c_){
    if(0 <= min(x,y) && y < screen.size() && x < screen[0].size() && screen[y][x] == c_){
        screen[y][x] = c;
        helper(screen, x+1,y,c,c_);
        helper(screen, x-1,y,c,c_);
        helper(screen, x,y+1,c,c_);
        helper(screen, x,y-1,c,c_);
    }
}

void fill(vector<vector<int>> &screen, int x, int y, int c){
    helper(screen, x,y,c,screen[y][x]);
}

int main(){
    vector<vector<int>> screen{{1, 1, 1, 1, 1, 1, 1, 1},
               {1, 1, 1, 1, 1, 1, 0, 0},
               {1, 0, 0, 1, 1, 0, 1, 1},
               {1, 2, 2, 2, 2, 0, 1, 0},
               {1, 1, 1, 2, 2, 0, 1, 0},
               {1, 1, 1, 2, 2, 2, 2, 0},
               {1, 1, 1, 1, 1, 2, 1, 1},
               {1, 1, 1, 1, 1, 2, 2, 1},
               };
    fill(screen, 4,4,3);
    vector<vector<int>> ans{{1, 1, 1, 1, 1, 1, 1, 1},
               {1, 1, 1, 1, 1, 1, 0, 0},
               {1, 0, 0, 1, 1, 0, 1, 1},
               {1, 3, 3, 3, 3, 0, 1, 0},
               {1, 1, 1, 3, 3, 0, 1, 0},
               {1, 1, 1, 3, 3, 3, 3, 0},
               {1, 1, 1, 1, 1, 3, 1, 1},
               {1, 1, 1, 1, 1, 3, 3, 1},
               };
    if(screen == ans){
        cout << "filled correctly" << endl;
    }else{
        cout << "you suck" << endl;
    }

    return 0;
}
