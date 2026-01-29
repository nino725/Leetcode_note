/*
有 n 个城市，按从 0 到 n-1 编号。给你一个边数组 edges，其中 edges[i] = [fromi, toi, weighti] 代表 fromi 和 toi 两个城市之间的双向加权边，距离阈值是一个整数 distanceThreshold。

返回在路径距离限制为 distanceThreshold 以内可到达城市最少的城市。如果有多个这样的城市，则返回编号最大的城市。

注意，连接城市 i 和 j 的路径的距离等于沿该路径的所有边的权重之和。
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
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector w(n,vector<int>(n,INT_MAX / 2));
        //记录每条边的权重
        for(auto& e : edges){
            int x = e[0], y = e[1], wt = e[2];
            w[x][y] = w[y][x] = wt;
        }

        vector memo(n,vector(n,vector<int>(n)));
        auto dfs = [&](this auto&& dfs, int k, int i, int j)->int{
            //边界条件，那一条边都不可以经过，只能直达;
            if(k < 0){
                return w[i][j];
            }

            auto& res = memo[k][i][j];
            if(res != 0){
                return res;
            }
            res = min(dfs(k - 1, i, j), dfs(k - 1,i,k)+dfs(k - 1,k,j));
            return res;
        };

        int ans = 0;
        int min_cnt = n;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(j != i && dfs(n - 1,i,j) <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= min_cnt){
                min_cnt = cnt;
                ans = i;
            }
        }
        return ans;
    }
};

//转换为递推
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector w(n,vector<int>(n,INT_MAX/2));
        for(auto& e : edges){
            int x = e[0], y = e[1], wt = e[2];
            w[x][y] = w[y][x] = wt; 
        }

        vector f(n + 1,vector(n,vector<int>(n)));
        f[0] = w; //边界条件，模拟小于0的情况
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    f[k + 1][i][j] = min(f[k][i][j],f[k][i][k]+f[k][k][j]);
                }
            }
        }
        /*
        空间优化
        auto f = move(w);
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
                }
            }
        }
        */
        
        int ans = 0;
        int min_cnt = n;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(j != i && f[n][i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= min_cnt){
                min_cnt = cnt;
                ans = i;
            }
        }
        return ans;
    }
};