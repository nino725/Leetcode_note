/*
给你一个 m x n 的二进制矩阵 mat。每一步，你可以选择一个单元格并将它反转（反转表示 0 变 1 ，1 变 0 ）。如果存在和它相邻的单元格，那么这些相邻的单元格也会被反转。相邻的两个单元格共享同一条边。

请你返回将矩阵 mat 转化为全零矩阵的最少反转次数，如果无法转化为全零矩阵，请返回 -1 。

二进制矩阵 的每一个格子要么是 0 要么是 1 。

全零矩阵 是所有格子都为 0 的矩阵。
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
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int start = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    start |= (1 << (i * n + j));
                }
            }
        }
        if(start == 0){
            return 0;
        }
        int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto reverseStr(int num,int i)->int{
            int col = i % n; //列
            int row = i / n; //行

            for(int k = 0; k < 5; k++){
                int x = row + dir[i][0];
                int y = col + dir[i][1];

                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int pos = x * n + y;
                    num ^= (1 << pos);
                }
            }
            return num;
        };

        unordered_map<int,int> dis;
        queue<int> q;
        dis[start] = 0;
        q.push(start);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int i = 0; i < m * n; i++){
                int p = reverse(x,i);
                if(!dis.count(p)){
                    dis[p] = dis[x] + 1;
                    q.push(p);
                }
                if(p == 0){
                    return dis[p];
                }
            }
        }
        return -1;
    
    }
};