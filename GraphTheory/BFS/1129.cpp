/*
给定一个整数 n，即有向图中的节点数，其中节点标记为 0 到 n - 1。图中的每条边为红色或者蓝色，并且可能存在自环或平行边。

给定两个数组 redEdges 和 blueEdges，其中：

redEdges[i] = [ai, bi] 表示图中存在一条从节点 ai 到节点 bi 的红色有向边，
blueEdges[j] = [uj, vj] 表示图中存在一条从节点 uj 到节点 vj 的蓝色有向边。
返回长度为 n 的数组 answer，其中 answer[X] 是从节点 0 到节点 X 的红色边和蓝色边交替出现的最短路径的长度。如果不存在这样的路径，那么 answer[x] = -1。

 
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
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> g(n);
        for(auto& e : redEdges){
            int x = e[0], y = e[1];
            g[x].push_back({y,1});
        }
        for(auto& e : blueEdges){
            int x = e[0], y = e[1];
            g[x].push_back({y,0});
        }

        queue<pair<int,int>> q;
        vector<vector<int>> dis(n,vector<int>(2,-1));
        dis[0][0] = 0;
        dis[0][1] = 0;
        q.push({0,1});
        q.push({0,0});
        while(!q.empty()){
            auto m = q.front();
            q.pop();
            int a = m.first, b = m.second;
            for(auto& p : g[a]){
                if(p.second != b && dis[p.first][p.second] < 0){
                    dis[p.first][p.second] = dis[a][b] + 1;
                    q.push(p);
                }
            }
        }
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            int a = dis[i][0], b = dis[i][1];
            if(a == -1){
                res[i] = b;
            }else if(b == -1){
                res[i] = a;
            }else{
                res[i] = min(a,b);
            }
        }
        return res;
    }
};