/*
给你一个整数数组 nums 和 两个 整数 l 和 r。你的任务是找到一个长度在 l 和 r 之间（包含）且和大于 0 的 子数组 的 最小 和。

返回满足条件的子数组的 最小 和。如果不存在这样的子数组，则返回 -1。

子数组 是数组中的一个连续 非空 元素序列。
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
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> f(n + 1);
        for(int i = 0; i < n; i++){
            f[i+1] = f[i] + nums[i];
        }

        int ans = INT_MAX;

        for(int i = 0; i < n; i++){
            for(int k = l; k <= r; k++){
                int x = i - k + 1;
                if(x < 0){
                    continue;
                }
                if(f[i+1] - f[x] > 0){
                    ans = min(ans, f[i+1] - f[x]);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};


class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int n = nums.size();
        vector<int> s(n+1);
        multiset<int> s_set; //允许重复元素的set
        for(int j = 1; j <= n; j++){

            //维护前缀和
            s[j] = s[j-1] + nums[j-1];
            if(j < l){
                continue;
            }

            //找最小前缀
            s_set.insert(s[j-l]);
            auto it = s_set.lower_bound(s[j]);
            if(it != s.begin()){
                ans = min(ans, s[j] - *--it);
            }

            //滑窗去除元素
            if(j >= r){
                s_set.erase(s_set.find(s[j-r]));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};