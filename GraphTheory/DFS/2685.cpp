#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

/*
给你一个整数 n 。现有一个包含 n 个顶点的 无向 图，顶点按从 0 到 n - 1 编号。给你一个二维整数数组 edges 其中 edges[i] = [ai, bi] 表示顶点 ai 和 bi 之间存在一条 无向 边。

返回图中 完全连通分量 的数量。

如果在子图中任意两个顶点之间都存在路径，并且子图中没有任何一个顶点与子图外部的顶点共享边，则称其为 连通分量 。

如果连通分量中每对节点之间都存在一条边，则称其为 完全连通分量 。

 
*/

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto& e : edges){
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<bool> vis(n);
        int e = 0, v = 0;
        auto dfs = [&](this auto&& dfs, int x)->void{
            vis[x] = true;
            e += g[x].size();
            v++;
            for(int& p : g[x]){
                if(!vis[p]){
                    dfs(p);
                }
            }
        };
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                e = 0, v = 0;
                dfs(i);
                if(e == v * (v - 1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};