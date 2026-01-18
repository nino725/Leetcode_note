#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    

    return 0;
}

/*
一个 k x k 的 幻方 指的是一个 k x k 填满整数的方格阵，且每一行、每一列以及两条对角线的和 全部相等 。幻方中的整数 不需要互不相同 。显然，每个 1 x 1 的方格都是一个幻方。

给你一个 m x n 的整数矩阵 grid ，请你返回矩阵中 最大幻方 的 尺寸 （即边长 k）。
*/

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector row_sum(m, vector<int>(n + 1));      // → 前缀和
        vector col_sum(m + 1, vector<int>(n));      // ↓ 前缀和
        vector diag_sum(m + 1, vector<int>(n + 1)); // ↘ 前缀和
        vector anti_sum(m + 1, vector<int>(n + 1)); // ↙ 前缀和

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = grid[i][j];
                row_sum[i][j + 1] = row_sum[i][j] + x;
                col_sum[i + 1][j] = col_sum[i][j] + x;
                diag_sum[i + 1][j + 1] = diag_sum[i][j] + x;
                anti_sum[i + 1][j] = anti_sum[i][j + 1] + x;
            }
        }

        for (int k = min(m, n); ; k--) {
            for (int i = k; i <= m; i++) {
                for (int j = k; j <= n; j++) {
                    int sum = diag_sum[i][j] - diag_sum[i - k][j - k];

                    if (anti_sum[i][j - k] - anti_sum[i - k][j] != sum) {
                        continue;
                    }

                    bool ok = true;
                    for (int r = i - k; r < i; r++) {
                        if (row_sum[r][j] - row_sum[r][j - k] != sum) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) {
                        continue;
                    }

                    for (int c = j - k; c < j; c++) {
                        if (col_sum[i][c] - col_sum[i - k][c] != sum) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        return k;
                    }
                }
            }
        }
    }
};
