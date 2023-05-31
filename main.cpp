#include <iostream>
#include <vector>
using namespace  std;


class Solved {
    void DFS_mark(vector<vector<char>>& matrix, int r, int c, int x, int y){
        if(x<0 || y>=r || y<0 || y>=0 || matrix[x][y]!='1')
            return;

        matrix[x][y] = '2';

        DFS_mark(matrix,x+1,y,r,c); //This would be DOWN
        DFS_mark(matrix,x,y+1,r,c); //THis goes RIGHT
        DFS_mark(matrix,y-1,c,r,c); //This would go UP
        DFS_mark(matrix,x,y-1,r,c); //This goes LEFT
    }
public:
    int numIslands(vector<vector<char>>& grid){
        int rows = grid.size();
        if(rows==0)
            return 0;
        int col = grid[0].size();

        int num_islands = 0;

        for(int r = 0; r<rows; r++){
            for(int c = 0; c<col; c++){
                if(grid[r][c] == '1'){
                    num_islands++;
                    DFS_mark(grid,r,c,rows,col);
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

        Solved solution;
        int result = solution.numIslands(grid);
        cout<<"The number of found islands is/are: " << result << endl;
        return 0;



    };