/*
给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。
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
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n+1);
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
            f[i+1] = f[i] + nums[i];
        }
        int ans = 0;

        unordered_map<int,int> local;
        for(int i = 0; i < n + 1; i++){
            if(local.contains(f[i])){
                ans = max(ans,i - local[f[i]]);
            }else{
                local[f[i]] = i;
            }
        }
        return ans;
    }
};