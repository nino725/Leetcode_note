/*
有一个具有 n 个顶点的 双向 图，其中每个顶点标记从 0 到 n - 1（包含 0 和 n - 1）。图中的边用一个二维整数数组 edges 表示，其中 edges[i] = [ui, vi] 表示顶点 ui 和顶点 vi 之间的双向边。 每个顶点对由 最多一条 边连接，并且没有顶点存在与自身相连的边。

请你确定是否存在从顶点 source 开始，到顶点 destination 结束的 有效路径 。

给你数组 edges 和整数 n、source 和 destination，如果从 source 到 destination 存在 有效路径 ，则返回 true，否则返回 false 。

 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}


//超内存
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector f(n,vector<int>(n));
        for(auto& p : edges){
            int x = p[0], y = p[1];
            f[x][y] = f[y][x] = 1;
        }

        vector<bool> vis(n,false);
        auto dfs = [&](this auto&& dfs,int x)->void{
            vis[x] = true;
            for(int i = 0; i < n; i++){
                if(f[x][i] == 1 && vis[i] == false){
                    dfs(i);
                }
            }
        };

        dfs(source);
        return vis[destination];
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> f;
        for(auto& p : edges){
            int x = p[0], y = p[1];
            f[x].push_back(y);
            f[y].push_back(x);
        }

        vector<bool> vis(n,false);
        auto dfs = [&](this auto&& dfs,int x)->void{
            vis[x] = true;
            for(int i : f[x]){
                if(vis[i] == false){
                    dfs(i);
                }
            }
        };

        dfs(source);
        return vis[destination];
    }
};