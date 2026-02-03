/*
有一个有 n 个节点的有向图，节点按 0 到 n - 1 编号。图由一个 索引从 0 开始 的 2D 整数数组 graph表示， graph[i]是与节点 i 相邻的节点的整数数组，这意味着从节点 i 到 graph[i]中的每个节点都有一条边。

如果一个节点没有连出的有向边，则该节点是 终端节点 。如果从该节点开始的所有可能路径都通向 终端节点（或另一个安全节点），则该节点为 安全节点。

返回一个由图中所有 安全节点 组成的数组作为答案。答案数组中的元素应当按 升序 排列。
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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        auto dfs = [&](this auto&& dfs,int x)->bool{
            if(color[x] > 0){
                return color[x] == 2;
            }

            color[x] = 1;
            for(int& p : graph[x]){
                if(!dfs(p)){
                    return false;
                }
            }
            color[x] = 2;
            return true;
        };

        vector<int> res;
        for(int i = 0; i < n; i++){
            if(dfs(i)){
               res.push_back(i);
            }
        }
        return res;
    }
};