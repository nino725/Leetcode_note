/*

给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

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
    vector<int> memo;
    int m;

    int dfs(vector<int>& nums, int i){
        int& res = memo[i];
        if(res != 0){
            return res;
        }
        for(int j = i - 1; j >= 0; j--){
            if(nums[i] > nums[j]){
                res = max(res, dfs(nums, j));
            }
        }
        return res += 1;
    }

    int lengthOfLIS(vector<int>& nums) {
        m = nums.size();
        memo = vector<int>(m,0);
        int ans = 0;
        for(int i = 0; i < m; i++){
            ans = max(ans, dfs(nums,i));
        }
        return ans;
    }
};


//转化为递推

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int m = nums.size();
        vector<int> f(m+1,1);
        for(int i = 0; i < m; i++){
            for(int j = i - 1; j >= 0; j--){
                if(nums[j] < nums[i]){
                    f[i+1] = max(f[i+1],f[j+1]+1);
                }
            }
        }      
        return ranges::max(f);
    }
};

//贪心+二分

class Solution {
public:
    int f(vector<int> a, int x){
        int l = 0, r = a.size() - 1;
        while(r >= l){
            int mid = l + (r - l)/2;
            if(a[mid] < x){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> g;
        for(int&x : nums){
            int j = f(g,x);
            if(j == g.size()){
                g.push_back(x);
            }else{
                g[j] = x;
            }
        }      
        return g.size();
    }
};