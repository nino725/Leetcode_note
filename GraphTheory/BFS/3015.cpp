/*
给你三个 正整数 n 、x 和 y 。

在城市中，存在编号从 1 到 n 的房屋，由 n 条街道相连。对所有 1 <= i < n ，都存在一条街道连接编号为 i 的房屋与编号为 i + 1 的房屋。另存在一条街道连接编号为 x 的房屋与编号为 y 的房屋。

对于每个 k（1 <= k <= n），你需要找出所有满足要求的 房屋对 [house1, house2] ，即从 house1 到 house2 需要经过的 最少 街道数为 k 。

返回一个下标从 1 开始且长度为 n 的数组 result ，其中 result[k] 表示所有满足要求的房屋对的数量，即从一个房屋到另一个房屋需要经过的 最少 街道数为 k 。

注意，x 与 y 可以 相等 。
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
    vector<int> countOfPairs(int n, int x, int y) {
        x--;
        y--;
        vector<vector<int>> g(n);
        for(int i = 0; i < n - 1; i++){
            g[i].push_back(i + 1);
            g[i + 1].push_back(i);
        }
        g[x].push_back(y);
        g[y].push_back(x);

        auto bfs = [&](int a){
            vector<int> dis(n, -1);
            queue<int> q;
            dis[a] = 0;
            q.push(a);
            while(!q.empty()){
                int b = q.front();
                q.pop();
                for(auto& p : g[b]){
                    if(dis[p] < 0){
                        dis[p] = dis[b] + 1;
                        q.push(p);
                    }
                }
            }
            return dis;
        };

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            auto m = bfs(i);
            for(int& p : m){
                if(p == 0){
                    continue;
                }
                ans[--p]++;
            }
        }
        return ans;
    }
};