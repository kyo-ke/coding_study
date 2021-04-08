#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

//most silly way is insert 1~9 to every zero and validate
//better way is calculate possible number and insert noly those numbers to zero
//best way is count efficiently using hashmap
//

void printvec(vector<vector<int>>);

bool validate(vector<vector<int>> &grid, int &x,int &y,int &i){
    bool ans(false);
    for(int j=0;j<9;j++){
        ans |= (grid[y][j] == i | grid[j][x] == i);
    }
    int stx((x/3)*3), sty((y/3)*3);
    for(int j=stx;j<stx+3;j++){
        for(int k=sty;k<sty+3;k++){
            ans |= grid[k][j] == i;
        }
    }
    return !ans;
}
//涙が出るくらい遅いけど一応解ける
void sudoku_solver(vector<vector<int>> grid){
    vector<vector<int>> c_grid;
    int c_n(0),x,y;
    queue<pair<vector<vector<int>>, int>> q;
    q.push(make_pair(grid, 0));
    while(!q.empty() && c_n < 81){
        c_grid = q.front().first;c_n = q.front().second;q.pop();
        y = c_n/9;x = c_n%9;
        cout << c_n << endl;
        cout << "value : " << c_grid[y][x] << endl;
        while(c_grid[y][x] != 0){
            c_n++;
            if(c_n == 81){
                break;
            }
            y = c_n/9;x = c_n%9;
        }
        cout << c_n << endl;
        if(c_n == 81){
            printvec(c_grid);
        }else{
            for(int i=1;i<10;i++){
                if(validate(c_grid, x,y ,i)){
                    c_grid[y][x] = i;
                    q.push(make_pair(c_grid, c_n));
                    c_grid[y][x] = 0;
                }
            }
        }
    }
}


//utility function for print 2Darray
void printvec(vector<vector<int>> vec){
    for(auto &v:vec){
        for(auto &i:v){
            cout << i << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> grid
    { { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
         { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
         { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
         { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
         { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
         { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
         { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
         { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
         { 7, 4, 5, 0, 8, 6, 3, 1, 0 } };
    sudoku_solver(grid);
    return 0;
}
