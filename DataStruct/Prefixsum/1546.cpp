/*
给你一个数组 nums 和一个整数 target 。

请你返回 非空不重叠 子数组的最大数目，且每个子数组中数字和都为 target 。
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
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();

        long long sum = 0;
        unordered_map<long long, int> cnt;
        cnt[0] = -1;

        int ans = 0;
        int last_end = -1;

        for(int i = 0; i < n; i++){
            sum += nums[i];

            long long x = sum - target;
            if(cnt.count(x) && cnt[x] >= last_end){
                //修改标记
                ans++;
                last_end = i;
            }

            cnt[sum] = i;
        }
        return ans;
    }
};