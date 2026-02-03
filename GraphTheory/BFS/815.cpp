/*
给你一个数组 routes ，表示一系列公交线路，其中每个 routes[i] 表示一条公交线路，第 i 辆公交车将会在上面循环行驶。

例如，路线 routes[0] = [1, 5, 7] 表示第 0 辆公交车会一直按序列 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... 这样的车站路线行驶。
现在从 source 车站出发（初始时不在公交车上），要前往 target 车站。 期间仅可乘坐公交车。

求出 最少乘坐的公交车数量 。如果不可能到达终点车站，返回 -1 。
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
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> bus;
        for(int i = 0; i < routes.size(); i++){
            for(int& p : routes[i]){
                bus[p].push_back(i);
            }
        }

        if(!bus.count(source) || !bus.count(target)){
            return source == target ? 0 : -1;
        }

        unordered_map<int,int> dis;
        dis[source] = 0;
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int x =q.front();
            q.pop();
            for(int i : bus[x]){
                for(int y : routes[i]){
                    if(!dis.count(y)){
                        dis[y] = dis[x] + 1;
                        q.push(y);
                    }
                }
                routes[i].clear();
            }
        }
        return dis.count(target) ? dis[target] : -1;
    }
};