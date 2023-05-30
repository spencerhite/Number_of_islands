#include <iostream>
#include <vector>
using namespace  std;


class Solved {
private:
    void DFS(vector<vector<char>>& grid, int r, int c){
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
    }
public:
    int numIslands(vector<vector<char>>& grid){
        int nr = grid.size();
        if(!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;

        for(int r = 0; r<nr; r++){
            for(int c = 0; c<nc; c++){
                if(grid[r][c] == '1'){
                    num_islands++;
                    DFS(grid,r,c);
                }
            }
        }
        return num_islands;
    }
};

    int main(int numIslands){
        vector<vector<char>> grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
        ];



    };