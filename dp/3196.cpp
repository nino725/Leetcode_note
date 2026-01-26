/*
给你一个长度为 n 的整数数组 nums。

子数组 nums[l..r]（其中 0 <= l <= r < n）的 成本 定义为：

cost(l, r) = nums[l] - nums[l + 1] + ... + nums[r] * (?1)r ? l

你的任务是将 nums 分割成若干子数组，使得所有子数组的成本之和 最大化，并确保每个元素 正好 属于一个子数组。

具体来说，如果 nums 被分割成 k 个子数组，且分割点为索引 i1, i2, ..., ik ? 1（其中 0 <= i1 < i2 < ... < ik - 1 < n - 1），则总成本为：

cost(0, i1) + cost(i1 + 1, i2) + ... + cost(ik ? 1 + 1, n ? 1)

返回在最优分割方式下的子数组成本之和的最大值。

注意：如果 nums 没有被分割，即 k = 1，则总成本即为 cost(0, n - 1)。
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
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<long long> memo;
        memo.assign(n,LLONG_MIN);
        auto f = [&](this auto&& f,int i)->long long{
            if(i < 0){
                return 0;
            }
            if(i == 0){
                return nums[0];
            }
            long long& res = memo[i];
            if(res != LLONG_MIN){
                return res;
            }

            res = max(f(i - 1) + nums[i],f(i - 2) - nums[i] + nums[i - 1]);
            return res;
        };
        return f(n - 1);
    }
};

class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<long long> f(n + 1, 0);
        f[1] = nums[0];
        for(int i = 1; i < n; i++){
            f[i+1] = max(f[i] + nums[i],f[i-1] + nums[i-1] - nums[i]);
        }
        return f[n];
    }
};