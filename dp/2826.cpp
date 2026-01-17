#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

int main() {
    
    return 0;
}

/*
给你一个整数数组 nums 。nums 的每个元素是 1，2 或 3。在每次操作中，你可以删除 nums 中的一个元素。返回使 nums 成为 非递减 顺序所需操作数的 最小值。
*/


//找最长递增子序列


//记忆化搜索
class Solution {
public:
    int n;
    vector<int> memo;

    int dfs(vector<int>& nums, int i){
        int& res = memo[i];
        if(res != -1){
            return res;
        }
        for(int j = i - 1; j >= 0; j--){
            if(nums[j] <= nums[i]){
                res = max(res, dfs(nums,j));
            }
        }
        return res = res + 1;
    }

    int minimumOperations(vector<int>& nums) {
        n = nums.size();
        memo = vector<int>(n,-1);
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, dfs(nums,i));
        }
        return n - ans - 1;
    }
};

//转化为递推
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n,1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] <= nums[i]){
                    f[i] = max(f[i],f[j] + 1);
                }
            }
        }
        return n - ranges::max(f);
    }
};

//贪心+二分 
class Solution {
public:
    int f(vector<int> &g, int val){
        int l = 0, r = g.size() - 1;
        while(r >= l){
            int mid = l + (r - l)/2;
            if(g[mid] < val){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }

    int minimumOperations(vector<int>& nums) {
        vector<int> g;
        for(int i = 0; i < nums.size(); i++){
            int loc = f(g,nums[i]+1);
            if(loc == g.size()){
                g.push_back(nums[i]);
            }else{
                g[loc] = nums[i];
            }
        }
        return nums.size() - g.size();
    }
};

//二维DP
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<array<int,4>> f(n+1);
        for(int i = 0 ; i < nums.size(); i++){
            int& x = nums[i];
            for(int j = 1; j < 4; j++){
                if(j < x){
                    f[i+1][j] = f[i][j];
                }else{
                    f[i+1][j] = max(f[i][j], f[i][x] + 1);
                }
            }
        }
        return n - f[n][3];
    }
};