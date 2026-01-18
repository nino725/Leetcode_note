/*
给你一个长度为 n 的数组 nums 和一个 正 整数 k 。

如果 nums 的一个子数组中，第一个元素和最后一个元素 差的绝对值恰好 为 k ，我们称这个子数组为 好 的。换句话说，如果子数组 nums[i..j] 满足 |nums[i] - nums[j]| == k ，那么它是一个好子数组。

请你返回 nums 中 好 子数组的 最大 和，如果没有好子数组，返回 0 。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    
    return 0;
}

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> f(n + 1);
        long long ans = LLONG_MIN;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            f[i + 1] = f[i] + nums[i];
            if (cnt.contains(nums[i] - k)) {
                ans = max(ans, f[i + 1] - f[cnt[nums[i] - k]]);
            }
            if (cnt.contains(nums[i] + k)) {
                ans = max(ans, f[i + 1] - f[cnt[nums[i] + k]]);
            }

            if (!cnt.count(nums[i]) || f[i] < f[cnt[nums[i]]]) {
                cnt[nums[i]] = i;
            }
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};