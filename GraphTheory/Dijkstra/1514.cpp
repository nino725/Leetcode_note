/*
给你一个由 n 个节点（下标从 0 开始）组成的无向加权图，该图由一个描述边的列表组成，其中 edges[i] = [a, b] 表示连接节点 a 和 b 的一条无向边，且该边遍历成功的概率为 succProb[i] 。

指定两个节点分别作为起点 start 和终点 end ，请你找出从起点到终点成功概率最大的路径，并返回其成功概率。

如果不存在从 start 到 end 的路径，请 返回 0 。只要答案与标准答案的误差不超过 1e-5 ，就会被视作正确答案。

 
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
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> g(n);
        for(int i = 0; i < edges.size(); i++){
            int x = edges[i][0], y = edges[i][1];
            double w = succProb[i];
            g[x].emplace_back(y,w);
            g[y].emplace_back(x,w);
        }      

        vector<double> dis(n);
        priority_queue<pair<double,int>> pq;
        dis[start_node] = 1;
        pq.emplace(1,start_node);
        while(!pq.empty()){
            auto [wx,x] = pq.top();
            pq.pop();
            if(wx < dis[x]){
                continue;
            }
            if(x == end_node){
                return wx;
            }
            for(auto [y,wy] : g[x]){
                double w = dis[x] * wy;
                if(w > dis[y]){
                    dis[y] = w;
                    pq.emplace(dis[y],y);
                }
            }
        }
        return dis[end_node];
    }
};