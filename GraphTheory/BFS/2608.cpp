/*
现有一个含 n 个顶点的 双向 图，每个顶点按从 0 到 n - 1 标记。图中的边由二维整数数组 edges 表示，其中 edges[i] = [ui, vi] 表示顶点 ui 和 vi 之间存在一条边。每对顶点最多通过一条边连接，并且不存在与自身相连的顶点。

返回图中 最短 环的长度。如果不存在环，则返回 -1 。

环 是指以同一节点开始和结束，并且路径中的每条边仅使用一次。

 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}


//仅能判断联通图
class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto& e : edges){
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }    

        vector<bool> vis(n,false);
        auto bfs = [&](int x)->int{
            queue<int> q;
            vis[x] = true;
            q.push(x);
            int v = 0;
            int e = 0;
            while(!q.empty()){
                int x = q.front();
                q.pop();
                e += g[x].size();
                v++;
                for(int& p : g[x]){
                    if(vis[p] == false){
                        vis[p] = true;
                        q.push(p);
                    }
                }
            }
            return v * 2 == e ? v : INT_MAX;
        };
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            if(vis[i] == false){
                ans = min(ans, bfs(i));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

//一个环可能共享结点

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto& e : edges){
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        auto bfs = [&](int x)->int{
            int ans = INT_MAX;
            vector<int> dis(n,-1);
            dis[x] = 0;
            queue<pair<int,int>> q;
            q.push({x, -1});
            while(!q.empty()){
                auto [a , fa] = q.front();
                q.pop();
                for(int y : g[a]){
                    if(dis[y] < 0){
                        dis[y] = dis[a] + 1;
                        q.push({y,a});
                    }else if(y != fa){
                        ans = min(ans, dis[a] + dis[y] + 1);
                    }
                }
            }
            return ans;
        };

        int res = INT_MAX;
        for(int i = 0; i < n; i++){
            res = min(res, bfs(i));
        }
        return res == INT_MAX ? -1 : res;
    }
};