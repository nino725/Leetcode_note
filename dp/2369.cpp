/*
给你一个下标从 0 开始的整数数组 nums ，你必须将数组划分为一个或多个 连续 子数组。

如果获得的这些子数组中每个都能满足下述条件 之一 ，则可以称其为数组的一种 有效 划分：

子数组 恰 由 2 个相等元素组成，例如，子数组 [2,2] 。
子数组 恰 由 3 个相等元素组成，例如，子数组 [4,4,4] 。
子数组 恰 由 3 个连续递增元素组成，并且相邻元素之间的差值为 1 。例如，子数组 [3,4,5] ，但是子数组 [1,3,5] 不符合要求。
如果数组 至少 存在一种有效划分，返回 true ，否则，返回 false 。
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
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n,-1);
        auto f = [&](this auto&&f, int i)->bool{
            if(i == n){
                return true;
            }
            if(i == n - 1){
                return false;
            }
            if(memo[i] != -1){
                return memo[i];
            }
            bool res = false;
            if(nums[i] == nums[i+1]){
                if(f(i+2)){
                    res = true;
                }
            }
            if(res == false && i + 2 < n){
                if(nums[i] == nums[i + 1] && nums[i + 1] == nums[i+2]){
                    if(f(i+3)){
                        res = true;
                    }
                }else if(nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1==nums[i + 2]){
                    if(f(i+3)){
                        res = true;
                    }
                }
            }
            return memo[i] = res;
        };
        return f(0);
    }
};

//递推
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> f(n + 1, false);
        f[0] = true;
        for(int i = 1; i < n; i++){
            f[i + 1] = f[i - 1] && (nums[i] == nums[i-1]);
            if(i > 1 && f[i+1] == false){
                f[i + 1] = f[i - 2] && (nums[i] == nums[i-2]) && (nums[i] == nums[i-1]);
                if(f[i+1] == false){
                    f[i+1] = f[i - 2] && (nums[i] == nums[i-2] + 2) && (nums[i] == nums[i-1] + 1);
                }
            }
        }  
        return f[n];
    }
};