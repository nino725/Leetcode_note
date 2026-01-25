#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

/*
给你一个下标从 0 开始的整数数组 nums 。现有一个长度等于 nums.length 的数组 arr 。对于满足 nums[j] == nums[i] 且 j != i 的所有 j ，arr[i] 等于所有 |i - j| 之和。如果不存在这样的 j ，则令 arr[i] 等于 0 。

返回数组 arr 。

 
*/

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> hash;
        for(int i = 0; i < nums.size(); i++){
            hash[nums[i]].push_back(i);
        }

        vector<long long> ans(nums.size(),0);
        for(auto& [_,a] : hash){
            int n = a.size();
            vector<long long> f(n + 1, 0);
            for(int i = 0; i < n; i++){
                f[i+1] = f[i] + a[i];
            } 

            for(int i = 0; i < n; i++){
                long long p = a[i];
                long long l = i * p - f[i];
                long long r = f[n] - f[i] - (n - i)*p;
                ans[p] = l + r ; 
            }
        }
        return ans;
    }
};