/*
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

子数组是数组中元素的连续非空序列。
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
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(n+1);
        int ans = 0;
        for(int i = 0; i < n; i++){
            f[i+1] = f[i] + nums[i];
        }
        unordered_map<int,int> cnt;
        for(int i = 0; i < n + 1; i++){
            if(cnt.contains(f[i] - k)){
                ans += cnt[f[i] - k];
            }
            cnt[f[i]]++;
        }
        return ans;
    }
};