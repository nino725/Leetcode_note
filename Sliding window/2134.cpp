#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

/*
交换 定义为选中一个数组中的两个 互不相同 的位置并交换二者的值。

环形 数组是一个数组，可以认为 第一个 元素和 最后一个 元素 相邻 。

给你一个 二进制环形 数组 nums ，返回在 任意位置 将数组中的所有 1 聚集在一起需要的最少交换次数。
*/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt_one = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                cnt_one++;
            }
        }
        vector<int> num(2 * n + 1);
        for(int i = 0; i < n; i++){
            num[i] = nums[i];
            num[i+n] = nums[i];
        }

        int max_one = 0, cnt = 0;
        for(int r = 0; r < cnt_one + n; r++){
            if(num[r] == 1){
                cnt++;
            }
            int l = r - cnt_one + 1;
            if(l < 0){
                continue;
            }
            max_one = max(max_one,cnt);
            if(num[l] == 1){
                cnt--;
            }
        }
        return cnt_one - max_one;
    }
};