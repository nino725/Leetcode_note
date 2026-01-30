/*
给你一个整数 n ，表示一张 无向图 中有 n 个节点，编号为 0 到 n - 1 。同时给你一个二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示节点 ai 和 bi 之间有一条 无向 边。

请你返回 无法互相到达 的不同 点对数目 。
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
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector w(n,vector<int>());
        for(auto& e : edges){
            int x = e[0], y = e[1];
            w[x].push_back(y);
            w[y].push_back(x);
        }

        vector<bool> vis(n,false);
        int cnt;
        auto dfs = [&](this auto&& dfs,int i)->int{
            vis[i] = true;
            cnt++;
            for(int p : w[i]){
                if(vis[p] == false){
                    dfs(p);
                }
            }
            return cnt;
        };

        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == false){
                cnt = 0;
                int x = dfs(i);
                ans +=1LL* x * (n - x);
            }
        }
        return ans / 2;
    }
};