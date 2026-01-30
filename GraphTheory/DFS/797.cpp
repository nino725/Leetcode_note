/*
给你一个有 n 个节点的 有向无环图（DAG），请你找出从节点 0 到节点 n-1 的所有路径并输出（不要求按特定顺序）

 graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。
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
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector f(n,vector<int>());
        for(int i = 0; i < n; i++){
            for(auto& p : graph[i]){
                f[i].push_back(p);
            }
        }

        vector<vector<int>> ans;
        vector<int> num;
        auto dfs = [&](this auto&& dfs,int x)->void{
            num.push_back(x);
            if(x == n - 1){
                ans.push_back(num);
            }
            for(int i : f[x]){
                dfs(i);
            }
            num.pop_back();
        };
        dfs(0);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> num;
        int n = graph.size();
        auto dfs = [&](this auto&& dfs,int x)->void{
            num.push_back(x);
            if(x == n - 1){
                ans.push_back(num);
            }
            for(int i : graph[x]){
                dfs(i);
            }
            num.pop_back();
        };
        dfs(0);
        return ans;
    }
};