#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
给定两个数组 nums1 和 nums2 ，返回 它们的 交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        //利用哈希集合去重
        unordered_set<int> hh(nums1.begin(), nums1.end());
        for(auto& p : nums2){
            if(hh.erase(p)){
                ans.push_back(p);
            }
        }
        return ans;
    }
};