#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

/*给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。

如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。
*/


//贪心+二分 和300一样
class Solution {
public:
    int f(vector<int>& a, int x){
        int l = 0, r = a.size()-1;
        while(r >= l){
            int mid = l + (r - l) / 2;
            if(a[mid] < x){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }

    bool increasingTriplet(vector<int>& nums) {
        vector<int> g;
        for(int& x : nums){
            int j = f(g,x);
            if(j == g.size()){
                g.push_back(x);
            }else{
                g[j] = x;
            }
        }
        return g.size() >= 3;
    }
};

//不能递推数据量太大会超时