#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

/*
给你一个整数 n 和一个二维整数数组 queries。

有 n 个城市，编号从 0 到 n - 1。初始时，每个城市 i 都有一条单向道路通往城市 i + 1（ 0 <= i < n - 1）。

queries[i] = [ui, vi] 表示新建一条从城市 ui 到城市 vi 的单向道路。每次查询后，你需要找到从城市 0 到城市 n - 1 的最短路径的长度。

返回一个数组 answer，对于范围 [0, queries.length - 1] 中的每个 i，answer[i] 是处理完前 i + 1 个查询后，从城市 0 到城市 n - 1 的最短路径的长度。
*/

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> g(n);
        
        for(int i = 0; i < n - 1; i++){
            g[i].push_back(i + 1);
        }

        auto f = [&](vector<int>& e)->void{
            int x = e[0], y = e[1];
            g[x].push_back(y);
        };

        vector<int> dis;
        auto bfs = [&](){
            dis.assign(n,-1);
            queue<int> q;
            dis[0] = 0;
            q.push(0);
            while(!q.empty()){
                int x = q.front();
                q.pop();
                for(int p : g[x]){
                    if(dis[p] < 0){
                        dis[p] = dis[x] + 1;
                        q.push(p);
                    }
                }
            }
        };

        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++){
            f(queries[i]);
            bfs();
            ans[i] = dis[n - 1];
        }
        return ans;
    }
};