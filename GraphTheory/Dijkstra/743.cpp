/*
有 n 个网络节点，标记为 1 到 n。

给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点， wi 是一个信号从源节点传递到目标节点的时间。

现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。

 
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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> g(n + 1);
        for(auto& e : times){
            int x = e[0], y = e[1], w = e[2];
            g[x].emplace_back(y,w);
        }
        vector<int> dis(n + 1,INT_MAX);
        dis[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dis[k] = 0;
        pq.emplace(0,k);

        while(!pq.empty()){
            auto [dis_x,x] = pq.top();
            pq.pop();
            if(dis_x > dis[x]){
                continue;
            }
            for(auto& [y,wt] : g[x]){
                auto new_dis_y = dis_x + wt;
                if(new_dis_y < dis[y]){
                    dis[y] = new_dis_y;
                    pq.emplace(new_dis_y,y);
                }
            }
        }
        int res = ranges::max(dis);
        return res == INT_MAX? -1 : res;
    }
};