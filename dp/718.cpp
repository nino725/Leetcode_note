#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

/*给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。*/
//二维数组dp
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> f(n+1,vector<int>(m+1,0));
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(nums1[i] == nums2[j]){
                    f[i+1][j+1] = f[i][j] + 1;
                    ans = max(ans,f[i+1][j+1]);
                }
            }
        }
        return ans;
    }
};

//空间优化
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums2.size();
        vector<int> f(m+1,0);
        int ans = 0;

        for(int& x : nums1){
            int pre = 0;
            for(int j = 0; j < m; j++){
                int tep = f[j+1];
                if(x == nums2[j]){
                    f[j+1] = pre + 1;
                    ans = max(ans,f[j+1]);
                }else{
                    f[j+1] = 0;
                }
                pre = tep;
            }
        }
        return ans;
    }
};
