/*
给你一个下标从 0 开始的整数数组nums 。每次操作中，你可以：

选择两个满足 0 <= i, j < nums.length 的不同下标 i 和 j 。
选择一个非负整数 k ，满足 nums[i] 和 nums[j] 在二进制下的第 k 位（下标编号从 0 开始）是 1 。
将 nums[i] 和 nums[j] 都减去 2k 。
如果一个子数组内执行上述操作若干次（包括 0 次）后，该子数组可以变成一个全为 0 的数组，那么我们称它是一个 美丽 的子数组。

请你返回数组 nums 中 美丽子数组 的数目。

子数组是一个数组中一段连续 非空 的元素序列。

注意：所有元素最初都是 0 的子数组被认为是美丽的，因为不需要进行任何操作。
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
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n+1,0);
        for(int i = 0; i < n; i++){
            f[i+1] = f[i] ^ nums[i];
        }

        long long ans = 0;
        unordered_map<int,int> cnt;
        for(int& x : f){
            if(cnt.contains(x ^ 0)){
                ans += cnt[x^0];
            }
            cnt[x]++;
        }
        return ans;
    }
};


class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        int s = 0;
        unordered_map<int,int> cnt{{0, 1}};
        for(int x : nums){
            s ^= x;
            ans += cnt[s];
            cnt[s]++;
        }
        return ans;
    }
};