#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    
    return 0;
}

/*
给你一个整数数组 arr 和一个整数值 target 。

请你在 arr 中找 两个互不重叠的子数组 且它们的和都等于 target 。可能会有多种方案，请你返回满足要求的两个子数组长度和的 最小值 。

请返回满足要求的最小长度和，如果无法找到这样的两个子数组，请返回 -1 。
*/

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<int> dp(n,1e9);

        unordered_map<long long : int> cnt;
        cnt[0] = -1;
        
        long long sum = 0;
        int min_len = 1e9;
        int best = 1e9;

        for(int i = 0; i < n; i++){
            sum += arr[i];

            if(cnt.count(sum - target)){
                int idx = cnt[sum - target];
                int len = i - idx;

                if(idx != -1 && dp[idx] != 1e9){
                    min_len = min(min_len, len + dp[idx]);
                }

                best = min(best, len);
            }

            if(i > 0){
                dp[i] = min(dp[i-1],best);
            }else{
                dp[i] = best;
            }

            cnt[sum] = i;
        }
        return (min_len >= 1e9) ? -1 : min_len;
    }
};