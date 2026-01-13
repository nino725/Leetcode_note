/*
在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。

现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足：

 nums1[i] == nums2[j]
且绘制的直线不与任何其他连线（非水平线）相交。
请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。

以这种方法绘制线条，并返回可以绘制的最大连线数
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}
//记忆化搜索
class Solution {
public:
    int n, m;
    vector<vector<int>> memo;

    int dfs(vector<int>& nums1, vector<int>& nums2, int i, int j){
        if(i == n || j == m){
            return 0;
        }
        int& res = memo[i][j];
        if(res != -1){
            return res;
        }
        if(nums1[i] == nums2[j]){
            res = dfs(nums1,nums2,i+1,j+1) + 1;
        }else{
            res = max(dfs(nums1,nums2,i+1,j),dfs(nums1,nums2,i,j+1));
        }
        return res;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size(),m = nums2.size();
        memo = vector<vector<int>>(n,vector<int>(m,-1));
        return dfs(nums1,nums2,0,0);
    }
};

//二维数组dp
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> f(n+1,vector<int>(m+1,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(nums1[i] == nums2[j]){
                    f[i+1][j+1] = f[i][j] + 1;
                }else{
                    f[i+1][j+1] = max(f[i][j+1],f[i+1][j]);
                }
            }
        }
        return f[n][m];
    }
};

//空间优化
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums2.size();
        vector<int> f(m+1,0);

        for(int& x : nums1){
            int pre = 0;
            for(int i = 0; i < m; i++){
                int tep = f[i+1];
                f[i+1] = x == nums2[i] ? pre+1 : max(f[i+1],f[i]);
                pre = tep;
            }
        }
        return f[m];
    }
};