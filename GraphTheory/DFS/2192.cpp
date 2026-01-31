/*
给你一个正整数 n ，它表示一个 有向无环图 中节点的数目，节点编号为 0 到 n - 1 （包括两者）。

给你一个二维整数数组 edges ，其中 edges[i] = [fromi, toi] 表示图中一条从 fromi 到 toi 的单向边。

请你返回一个数组 answer，其中 answer[i]是第 i 个节点的所有 祖先 ，这些祖先节点 升序 排序。

如果 u 通过一系列边，能够到达 v ，那么我们称节点 u 是节点 v 的 祖先 节点。
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
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto& e : edges){
            int x = e[0], y = e[1];
            g[y].push_back(x);
        }

        vector<bool> vis(n,false);
        auto dfs = [&](this auto&& dfs, int x)->void{
            vis[x] = true;
            for(int& p : g[x]){
                if(!vis[p]){
                    dfs(p);
                }
            }
        };

        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++){
            vis.assign(n,false);
            dfs(i);
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                if(vis[j] == true){
                    ans[i].push_back(j);
                }
            }
        }
        return ans;
    }
};