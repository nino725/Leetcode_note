/*
给你一个大小为 m x n 的矩阵 mat 和一个整数阈值 threshold。

请你返回元素总和小于或等于阈值的正方形区域的最大边长；如果没有这样的正方形区域，则返回 0 。

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
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                f[i+1][j+1] = f[i+1][j] + f[i][j+1] - f[i][j] + mat[i][j];
            }
        }

        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = min(i, j); k >= 0; k--){
                    int new_i = i - k, new_j = j - k;
                    if(f[i+1][j+1] - f[i+1][new_j] - f[new_i][j+1] + f[new_i][new_j] <= threshold){
                        ans = max(ans,k+1);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector sum(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];
            }
        }

        // 返回左上角在 (r1, c1)，右下角在 (r2, c2) 的子矩阵元素和
        auto query = [&](int r1, int c1, int r2, int c2) -> int {
            return sum[r2 + 1][c2 + 1] - sum[r2 + 1][c1] - sum[r1][c2 + 1] + sum[r1][c1];
        };

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 边长为 ans+1 的正方形，左上角在 (i, j)，右下角在 (i+ans, j+ans)
                while (i + ans < m && j + ans < n && query(i, j, i + ans, j + ans) <= threshold) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
