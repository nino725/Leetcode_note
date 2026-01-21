/*
我们定义 arr 是 山形数组 当且仅当它满足：

arr.length >= 3
存在某个下标 i （从 0 开始） 满足 0 < i < arr.length - 1 且：
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
给你整数数组 nums? ，请你返回将 nums 变成 山形状数组 的? 最少 删除次数。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}


//找最大的山形数组

//找最大最小拼接

//1.记忆化搜索
class Solution {
public:
    vector<int> memo;
    int dfs(vector<int>& nums,int i){
        int& res = memo[i];
        if(res != -1){
            return res;
        }
        res = 1;
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                res = max(res, dfs(nums,j) + 1);
            }
        }
        return res;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        memo = vector<int>(n,-1);
        vector<int> pre(n,0);
        vector<int> suf(n,0);
        for(int i = 0; i < n; i++){
            pre[i] += dfs(nums,i);
        }
        memo = vector<int>(n,-1);
        reverse(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            suf[n - 1 - i] += dfs(nums, i);
        }
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            if (pre[i] > 1 && suf[i] > 1) {
                max_len = max(max_len, pre[i] + suf[i] - 1);
            }
        }
        return n - max_len;
    }
};

//二分+贪心
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n) , g;
        for(int i = n - 1;i > 0; i--){
            auto it = lower_bound(g.begin(),g.end(),nums[i]);
            suf[i] = it - g.begin() + 1;
            if(it == g.end()){
                g.push_back(nums[i]);
            }else{
                *it = nums[i];
            }
        }

        int mx = 0;
        g.clear();
        for(int i = 0; i < n; i++){
            auto it = lower_bound(g.begin(),g.end(),nums[i]);
            int pre = it - g.begin() + 1;
            if(it == g.end()){
                g.push_back(nums[i]);
            }else{
                *it = nums[i];
            }
            if(suf[i] > 1 && pre > 1){
                mx = max(mx,pre + suf[i] - 1);
            }
        }
        return n-mx;
    }
};