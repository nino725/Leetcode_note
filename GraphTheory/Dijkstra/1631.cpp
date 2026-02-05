/*
你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子 (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。

一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。

请你返回从左上角走到右下角的最小 体力消耗值 。

 
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
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> dis(row,vector<int>(col,INT_MAX));
        int dist[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        dis[0][0] = 0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto e = pq.top();
            pq.pop();
            int w = e[0], x = e[1], y = e[2];
            if(w > dis[x][y]){
                continue;
            }
            for(auto [r0,r1] : dist){
                int a = x + r0, b = y + r1;
                if(a >= 0 && a < row && b >= 0 && b < col){
                    int wt = max(dis[x][y],abs(heights[a][b] - heights[x][y]));
                    if(wt < dis[a][b]){
                        dis[a][b] = wt;
                        pq.push({wt,a,b});
                    }
                }
            }
        }  
        return dis[row-1][col-1];
    }
};