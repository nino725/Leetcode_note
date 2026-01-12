/*
给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        ranges::sort(nums1);
        ranges::sort(nums2);

        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;

        vector<int> ans;
        while(i < m && j < n){
            int x = nums1[i], y = nums2[j];
            if(x > y){
                j++;
            }else if(x < y){
                i++;
            }else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};