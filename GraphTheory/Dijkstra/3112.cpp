/*
给你一个二维数组 edges 表示一个 n 个点的无向图，其中 edges[i] = [ui, vi, lengthi] 表示节点 ui 和节点 vi 之间有一条需要 lengthi 单位时间通过的无向边。

同时给你一个数组 disappear ，其中 disappear[i] 表示节点 i 从图中消失的时间点，在那一刻及以后，你无法再访问这个节点。

注意，图有可能一开始是不连通的，两个节点之间也可能有多条边。

请你返回数组 answer ，answer[i] 表示从节点 0 到节点 i 需要的 最少 单位时间。如果从节点 0 出发 无法 到达节点 i ，那么 answer[i] 为 -1 。

 
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
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> g(n);
        for(auto& e : edges){
            int x = e[0], y = e[1], wt = e[2];
            g[x].emplace_back(y,wt);
            g[y].emplace_back(x,wt);
        }    

        vector<vector<int>> dis(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
        dis[0] = 0;
        pq.emplace(0,0);
        while(!pq.empty()){
            auto [v,x] = pq.top();
            pq.pop();
            if(v > dis[x]){
                continue;
            }
            for(auto [y,wy] : g[x]){
                int w = dis[x] + wy;
                if(w < INT_MAX && w < disappear[y]){
                    dis[y] = w;
                    pq.emplace(dis[y],y);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(dis[i] == INT_MAX){
                dis[i] = -1;
            }
        }
        return dis;
    }
};