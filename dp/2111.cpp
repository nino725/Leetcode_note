/*
给你一个下标从 0 开始包含 n 个正整数的数组 arr ，和一个正整数 k 。

如果对于每个满足 k <= i <= n-1 的下标 i ，都有 arr[i-k] <= arr[i] ，那么我们称 arr 是 K 递增 的。

比方说，arr = [4, 1, 5, 2, 6, 2] 对于 k = 2 是 K 递增的，因为：
arr[0] <= arr[2] (4 <= 5)
arr[1] <= arr[3] (1 <= 2)
arr[2] <= arr[4] (5 <= 6)
arr[3] <= arr[5] (2 <= 2)
但是，相同的数组 arr 对于 k = 1 不是 K 递增的（因为 arr[0] > arr[1]），对于 k = 3 也不是 K 递增的（因为 arr[0] > arr[3] ）。
每一次 操作 中，你可以选择一个下标 i 并将 arr[i] 改成任意 正整数。

请你返回对于给定的 k ，使数组变成 K 递增的 最少操作次数 。
*/


//找最长的K递增长度
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    
    return 0;
}

class Solution {
public:
    int f(vector<int>& g, int x){
        int l = 0, r = g.size() - 1;
        while(r >= l){
            int mid = l + (r - l) / 2;
            if(g[mid] < x){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }

    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> cnt(k,0);
        for(int p = 0; p < k; p++){
            vector<int> g;
            for(int i = p; i < n; i += k){
                int loc = f(g,arr[i] + 1);
                if(loc >= g.size()){
                    g.push_back(arr[i]);
                }else{
                    g[loc] = arr[i];
                }
            }
            cnt[p] = g.size();
        }
        return n - reduce(cnt.begin(),cnt.end(),0);
    }
};