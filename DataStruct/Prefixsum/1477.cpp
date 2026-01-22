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
        vector<int> f(n);
        for(int i = 0; i < n; i++){
            f[i+1] = f[i] + arr[i];
        }

        unordered_map<int,int> cnt;
        for(int i = 0; i < n; i++){
            int x = f[i + 1];
            if(cnt.count(x - target)){

            }
        }
    }
};