#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

/*
给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
*/


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int& p : nums){
            int x = (p - 1) % n;
            if(nums[x] <= n){
                nums[x] += n;
            }
        }
        vector<int> ans;
        for(int i = 0; i < n;i++){
            if(nums[i] <= n){
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};