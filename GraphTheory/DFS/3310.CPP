#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    return 0;
}

/*
你正在维护一个项目，该项目有 n 个方法，编号从 0 到 n - 1。

给你两个整数 n 和 k，以及一个二维整数数组 invocations，其中 invocations[i] = [ai, bi] 表示方法 ai 调用了方法 bi。

已知如果方法 k 存在一个已知的 bug。那么方法 k 以及它直接或间接调用的任何方法都被视为 可疑方法 ，我们需要从项目中移除这些方法。

只有当一组方法没有被这组之外的任何方法调用时，这组方法才能被移除。

返回一个数组，包含移除所有 可疑方法 后剩下的所有方法。你可以以任意顺序返回答案。如果无法移除 所有 可疑方法，则 不 移除任何方法。
*/


class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector G(n,vector<int>());
        vector N(n,vector<int>());
        for(auto& e : invocations){
            int x = e[0], y = e[1];
            G[x].push_back(y);
            N[x].push_back(y);
            N[y].push_back(x);
        }

        vector<bool> vis(n,false);
        int cnt = 0;
        auto dfs = [&](this auto&& dfs, int x, vector<vector<int>>& W)->int{
            vis[x] = true;
            for(int& p : W[x]){
                if(!vis[p]){
                    dfs(p,W);
                }
            }
            return cnt += 1;
        };

        int x = dfs(k,G);
        cnt = 0;
        vis.assign(n,false);
        int y = dfs(k,N);
        vector<int> ans;
        if(x != y){
            for(int i = 0; i < n; i++){
                ans.push_back(i);
            }
        }else{
            for(int i = 0; i < n; i++){
                if(vis[i] == false){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n);
        for(auto& e : invocations){
            int x = e[0], y = e[1];
            g[x].push_back(y);
        }

        vector<bool> vis(n,false);
        auto dfs = [&](this auto&& dfs, int x)->void{
            vis[x] = true;
            for(int& p : g[x]){
                if(!vis[p]){
                    dfs(p);
                }
            }
        }
        dfs(k);

        for(auto& e : invocations){
            int x = e[0], y = e[1];
            if(!vis[x] && vis[y]){
                vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ans.push_back[i];
            }
        }
        return ans;
    }
};