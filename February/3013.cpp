/*
给你一个下标从 0 开始长度为 n 的整数数组 nums 和两个 正 整数 k 和 dist 。

一个数组的 代价 是数组中的 第一个 元素。比方说，[1,2,3] 的代价为 1 ，[3,4,1] 的代价为 3 。

你需要将 nums 分割成 k 个 连续且互不相交 的子数组，满足 第二 个子数组与第 k 个子数组中第一个元素的下标距离 不超过 dist 。换句话说，如果你将 nums 分割成子数组 nums[0..(i1 - 1)], nums[i1..(i2 - 1)], ..., nums[ik-1..(n - 1)] ，那么它需要满足 ik-1 - i1 <= dist 。

请你返回这些子数组的 最小 总代价。
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
    long long minimumCost(vector<int>& nums, int k, int dist) {
        k--;
        long long sum = reduce(nums.begin(), nums.begin() + dist + 2, 0LL);
        multiset<int> L(nums.begin() + 1, nums.begin() + dist + 2), R;
        auto L2R = [&](){
            int x = *L.rbegin();
            sum -= x;
            L.erase(L.find(x));
            R.insert(x);
        };

        auto R2L = [&](){
            int x = *R.begin();
            sum += x;
            R.erase(R.find(x));
            L.insert(x);
        };

        while(L.size() > k){
            L2R();
        }

        long long ans = sum;
        for(int i = dist + 2; i < nums.size(); i++){
            int out = nums[i - dist - 1];
            auto it = L.find(out);
            if(it != L.end()){
                sum -= out;
                L.erase(it);
            }else{
                R.erase(R.find(out));
            }
            
            int in = nums[i];
            if(in < *L.rbegin()){
                sum += in;
                L.insert(in);
            }else{
                R.insert(in);
            }
            
            if(L.size() == k - 1){
                R2L();
            }else if(L.size() == k + 1){
                L2R();
            }
            
            ans = min(ans, sum);
        }
        return ans;
    }
};