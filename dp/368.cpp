/*
给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i], answer[j]) 都应当满足：
answer[i] % answer[j] == 0 ，或
answer[j] % answer[i] == 0
如果存在多个有效解子集，返回其中任何一个均可。
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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> memo(n), from(n, -1);

        auto dfs = [&](this auto&& dfs, int i){
            int& res = memo[i];
            if(res != 0){
                return res;
            }
            res = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    int f = dfs(j);
                    if(f + 1 > res){
                        res = f + 1;
                        from[i] = j;
                    }
                }
            }
            return res;
        };

        vector<int> ans;
        int max_f = 0, max_i = 0;
        for(int i = 0; i < n; i++){
            int f = dfs(i);
            if(f > max_f){
                max_f = f;
                max_i = i;
            }
        }

        for(int i = max_i; i >= 0; i = from[i]){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int max_f = 0, max_i = 0;
        vector<int> f(n + 1,1),from(n,-1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(f[j+1] + 1 > f[i+1]){
                        f[i+1] = f[j+1] + 1;
                        from[i] = j;
                    }
                }
            }
            if(f[i+1] > max_f){
                max_f = f[i+1];
                max_i = i;
            }
        }

        vector<int> ans;
        for(int i = max_i; i > 0; i = from[i]){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};