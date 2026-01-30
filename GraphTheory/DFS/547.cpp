/*
有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector solves(n,vector<int>(n));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                solve[i][j] = isConnected[i][j];
            }
        }

        vector<bool> vis(n,false);
        auto dfs = [&](this auto&& dfs,int x){
            vis[x] = true;
            for(int p : solves[x]){
                if(solves[x][p] == 1 && vis[p] == false){
                    vis[p] = true; 
                }
            }
        };

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i);
                cnt++;
            }
        }
        return cnt;
    }
};