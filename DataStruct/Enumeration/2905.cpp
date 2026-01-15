/*
给你一个下标从 0 开始、长度为 n 的整数数组 nums ，以及整数 indexDifference 和整数 valueDifference 。

你的任务是从范围 [0, n - 1] 内找出  2 个满足下述所有条件的下标 i 和 j ：

abs(i - j) >= indexDifference 且
abs(nums[i] - nums[j]) >= valueDifference
返回整数数组 answer。如果存在满足题目要求的两个下标，则 answer = [i, j] ；否则，answer = [-1, -1] 。如果存在多组可供选择的下标对，只需要返回其中任意一组即可。

注意：i 和 j 可能 相等 。
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
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int max_j = INT_MIN, min_j = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int left = i - indexDifference + 1;
            if(left < 0){
                continue;
            }
            if(nums[left] > nums[max_j]){
                max_j = left;
            }
            if(nums[left] < nums[min_j]){
                min_j = left;
            }

            if(nums[max_j] - nums[i] >= valueDifference){
                return {i,max_j};
            }
            if(nums[i] - nums[min_j] >= valueDifference){
                return {i,min_j};
            }
        }
        return {-1,-1};
    }
};