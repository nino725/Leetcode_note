/*
给你一个长度为 n 的整数数组 nums。

三段式子数组 是一个连续子数组 nums[l...r]（满足 0 <= l < r < n），并且存在下标 l < p < q < r，使得：

nums[l...p] 严格 递增，
nums[p...q] 严格 递减，
nums[q...r] 严格 递增。
请你从数组 nums 的所有三段式子数组中找出和最大的那个，并返回其 最大 和。

 
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
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        for(int i = 0; i < n;){
            int start = i;
            for(i++; i < n && nums[i] > nums[i-1]; i++);
            if(i == start + 1){
                continue;
            }

            int peak = i - 1;
            long long res = nums[peak-1] + nums[peak];
            for(; i < n && nums[i-1] > nums[i]; i++){
                res += nums[i];
            }
            if(i == peak + 1 || i == n || nums[i-1] == nums[i]){
                continue;
            }

            int bottom = i - 1;
            res += nums[i];
            long long max_s = 0, s = 0;
            for(i++; i < n && nums[i-1] < nums[i]; i++){
                s += nums[i];
                max_s = max(max_s, s);
            }
            res += max_s;

            max_s = 0; s = 0;
            for(int j = peak - 2; j >= start; j--){
                s+= nums[j];
                max_s = max(max_s,s);
            }
            res += max_s;
            ans = max(ans,res);

            i = bottom;
        }
        return ans;
    }
};