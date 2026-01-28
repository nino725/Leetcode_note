#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

/*
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> memo(n,vector<int>(m,-1));
        auto f = [&](this auto&& f,int i, int j)->int{
            if(i == n - 1 && j == m - 1){
                return grid[i][j];
            }
            if(i == n){
                return INT_MAX / 2;
            }
            if(j == m){
                return INT_MAX / 2;
            }
            int& res = memo[i][j];
            if(res != -1){
                return res;
            }
            res = min(f(i+1,j), f(i,j+1)) + grid[i][j];
            return res;
        };
        return f(0,0);
    }
};