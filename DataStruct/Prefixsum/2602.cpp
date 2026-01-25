#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

/*
给你一个正整数数组 nums 。

同时给你一个长度为 m 的整数数组 queries 。第 i 个查询中，你需要将 nums 中所有元素变成 queries[i] 。你可以执行以下操作 任意 次：

将数组里一个元素 增大 或者 减小 1 。
请你返回一个长度为 m 的数组 answer ，其中 answer[i]是将 nums 中所有元素变成 queries[i] 的 最少 操作次数。

注意，每次查询后，数组变回最开始的值。
*/

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = queries.size();
        vector<long long> ans(n);

        int m = nums.size();
        vector<long long> f(m + 1,0);
        for(int i = 0; i < m; i++){
            f[i+1] = f[i] + nums[i];
        }

        auto f1 = [&](int val)->int{
            int l = 0, r = m - 1;
            while(r >= l){
                int mid = l + (r - l) / 2;
                if(nums[mid] < val){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            return l;
        };

        for(int i = 0; i < n; i++){
            long long loc = f1(queries[i]);
            long long l = queries[i] * loc - f[loc];
            long long r = f[m] - f[loc] - queries[i] * (m - loc);
            ans[i] = l + r;
        }
        return ans;
    }
};