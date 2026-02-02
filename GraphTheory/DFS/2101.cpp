/*
给你一个炸弹列表。一个炸弹的 爆炸范围 定义为以炸弹为圆心的一个圆。

炸弹用一个下标从 0 开始的二维整数数组 bombs 表示，其中 bombs[i] = [xi, yi, ri] 。xi 和 yi 表示第 i 个炸弹的 X 和 Y 坐标，ri 表示爆炸范围的 半径 。

你需要选择引爆 一个 炸弹。当这个炸弹被引爆时，所有 在它爆炸范围内的炸弹都会被引爆，这些炸弹会进一步将它们爆炸范围内的其他炸弹引爆。

给你数组 bombs ，请你返回在引爆 一个 炸弹的前提下，最多 能引爆的炸弹数目。
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
    int maximumDetonation(vector<vector<int>>& bombs) {
        auto f = [&](vector<int>& a, vector<int>& b)->bool{
            long long dis = 1LL*(b[0] - a[0]) * (b[0] - a[0]) + 1LL*(b[1] - a[1]) * (b[1] - a[1]);
            return 1LL*a[2] * a[2] >= dis;
        };

        int n = bombs.size();
        vector<vector<int>> G(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && f(bombs[i],bombs[j])){
                    G[i].push_back(j);
                }
            }
        }

        vector<bool> vis(n,false);
        int cnt = 0;
        auto dfs = [&](this auto&& dfs,int x)->int{
            cnt++;
            vis[x] = true;
            for(int& p : G[x]){
                if(!vis[p]){
                    dfs(p);
                }
            }
            return cnt;
        };

        int ans = 0;
        for(int i = 0; i < n; i++){
            vis.assign(n,false);
            cnt = 0;
            int x = dfs(i);
            ans = max(ans, x);
            if(ans == n){
                return ans;
            }
        }
        return ans;
    }
};