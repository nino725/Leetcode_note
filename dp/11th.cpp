
/*
给你一个整数数组 rewardValues，长度为 n，代表奖励的值。

最初，你的总奖励 x 为 0，所有下标都是 未标记 的。你可以执行以下操作 任意次 ：

从区间 [0, n - 1] 中选择一个 未标记 的下标 i。
如果 rewardValues[i] 大于 你当前的总奖励 x，则将 rewardValues[i] 加到 x 上（即 x = x + rewardValues[i]），并 标记 下标 i。
以整数形式返回执行最优操作能够获得的 最大 总奖励。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


/*
记忆化搜索，爆内存了

修改memo上界，体会为什么是2*max(rewardValues)
*/
class Solution {
public:
    vector<vector<int>> memo;
    int n;

    int dfs(vector<int>& rewardValues, int i, int total) {
        if (i == n) {
            return 0;
        }
        int& res = memo[i][total];
        if (res != -1) {
            return res;
        }
        if (rewardValues[i] > total) {
            res = max(dfs(rewardValues, i + 1, total),
                      rewardValues[i] + dfs(rewardValues, i + 1, total + rewardValues[i]));
        } else {
            res = dfs(rewardValues, i + 1, total);
        }
        return res;
    }

    int maxTotalReward(vector<int>& rewardValues) {
        n = rewardValues.size();
        int total = 2 *ranges::max(rewardValues);
        memo = vector<vector<int>>(n, vector<int>(total + 1, -1));
        ranges::sort(rewardValues.begin(), rewardValues.end());
        int totalReward = 0;
        return dfs(rewardValues, 0, 0);
    }
};

/*动态规划 不是用递归的二维数组*/
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        int val = 2 * ranges::max(rewardValues);
        vector<vector<bool>> f(n + 1, vector<bool>(val, false));
        f[0][0] = true;
        ranges::sort(rewardValues.begin(), rewardValues.end());
        int j = 0;
        for (int i = 0; i < n; i++) {
            int v = rewardValues[i];
            for (int j = 0; j < val; j++) {
                if (f[i][j]) {
                    f[i + 1][j] = true;
                    if (j < v && j + v < val) {
                        f[i + 1][j + v] = true;
                    }
                }
            }
            for (int j = val - 1; j >= 0; j--) {
                if (f[n][j]) {
                    return j;
                }
            }
        }
        return 0;
    }
};
