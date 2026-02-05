/*
给你一个 正 整数 k ，同时给你：

一个大小为 n 的二维整数数组 rowConditions ，其中 rowConditions[i] = [abovei, belowi] 和
一个大小为 m 的二维整数数组 colConditions ，其中 colConditions[i] = [lefti, righti] 。
两个数组里的整数都是 1 到 k 之间的数字。

你需要构造一个 k x k 的矩阵，1 到 k 每个数字需要 恰好出现一次 。剩余的数字都是 0 。

矩阵还需要满足以下条件：

对于所有 0 到 n - 1 之间的下标 i ，数字 abovei 所在的 行 必须在数字 belowi 所在行的上面。
对于所有 0 到 m - 1 之间的下标 i ，数字 lefti 所在的 列 必须在数字 righti 所在列的左边。
返回满足上述要求的 任意 矩阵。如果不存在答案，返回一个空的矩阵。
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
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> dis_row(k), dis_col(k);
        vector<vector<int>> g_row(k), g_col(k);
        for(auto& e : rowConditions){
            int x = e[0] - 1, y = e[1] - 1;
            dis_row[y]++;
            g_row[x].push_back(y);
        }
        for(auto& e : colConditions){
            int x = e[0] - 1, y = e[1] - 1;
            dis_col[y]++;
            g_col[x].push_back(y);
        }

        queue<int> q_row,q_col;
        for(int i = 0; i < k; i++){
            if(dis_row[i] == 0){
                q_row.push(i);
            }
            if(dis_col[i] == 0){
                q_col.push(i);
            }
        }

        vector<int> row,col;
        while(!q_row.empty()){
            int x = q_row.front();
            q_row.pop();
            row.push_back(x);
            for(int& p : g_row[x]){
                dis_row[p]--;
                if(dis_row[p] == 0){
                    q_row.push(p);
                }
            }
        }
        while(!q_col.empty()){
            int x = q_col.front();
            q_col.pop();
            col.push_back(x);
            for(int& p : g_col[x]){
                dis_col[p]--;
                if(dis_col[p] == 0){
                    q_col.push(p);
                }
            }
        }
        if(row.size() < k || col.size() < k){
            return {};
        }

        vector<vector<int>> res(k, vector<int>(k, 0));
        vector<pair<int,int>> loc(k);
        for(int i = 0; i < k; i++){
            loc[row[i]].first = i;
            loc[col[i]].second = i;
        }

        for(int i = 0; i < k; i++){
            int x = loc[i].first, y = loc[i].second;
            res[x][y] = i + 1;
        }
        return res;
    }
};