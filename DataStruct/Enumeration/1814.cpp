#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    

    return 0;
}

/*
给你一个数组 nums ，数组中只包含非负整数。定义 rev(x) 的值为将整数 x 各个数字位反转得到的结果。比方说 rev(123) = 321 ， rev(120) = 21 。我们称满足下面条件的下标对 (i, j) 是 好的 ：

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
请你返回好下标对的数目。由于结果可能会很大，请将结果对 109 + 7 取余 后返回。

*/


class Solution {
public:
    int reverse(int num){
        int ans = 0;
        while(num > 0){
            ans = ans * 10 + num % 10;
            num = num / 10;
        }
        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> cnt;
        long long result = 0;
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i] - reverse(nums[i]);
            if(cnt.contains(x)){
                result += cnt[x];
            }
            cnt[x]++;
        }
        return result % 1000000007;
    }
};