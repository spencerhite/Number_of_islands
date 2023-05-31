//
// Created by Spencer on 5/29/23.
//

#include <iostream>
#include <vector>
using namespace  std;


class Solved {
    void DFS_mark(vector<vector<char>>& matrix, int r, int c, int x, int y){
        if(x<0 || y>=r || y<0 || x>=c || matrix[x][y]!='1')
            return;

        matrix[x][y] = '2';

        DFS_mark(matrix,r,c,x+1,y); //This would be DOWN
        DFS_mark(matrix,r,c,x,y+1); //THis goes RIGHT
        DFS_mark(matrix,r,c,x-1,y); //This would go UP
        DFS_mark(matrix,r,c,x,y-1); //This goes LEFT
    }
public:
    int numIslands(vector<vector<char>>& grid,int x,int y){

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int rows = grid.size();
        if(rows==0)
            return 0;
        int col = grid[0].size();

        int num_islands = 0;

        for(int r = x; r<rows; r++){
            for(int c = y; c<col; c++){
                if(grid[r][c] == '1'){
                    num_islands++;
                    DFS_mark(grid,rows,col,r,c);
                }
            }
        }
        return num_islands;
    }
};

int main(int numIslands){
    vector<vector<char>> grid =
            {{'1','1','1','1','0'},
             {'1','1','0','1','0'},
             {'1','1','0','0','0'},
             {'0','0','0','0','0'}};

    int x = 0;
    int y =0;

    Solved solution;
    int result = solution.numIslands(grid, x, y);
    cout<<"The number of found islands is/are: " << result << endl;
    return 0;



};