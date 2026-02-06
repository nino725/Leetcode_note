/*
给你一个由 互不相同 的正整数组成的数组 nums，需要根据每个数字的数位和（即每一位数字相加求和）按 升序 对数组进行排序。如果两个数字的数位和相等，则较小的数字排在前面。

返回将 nums 排列为上述排序顺序所需的 最小 交换次数。

一次 交换 定义为交换数组中两个不同位置的值。
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
    int minSwaps(vector<int>& nums) {
        auto NumAdd = [&](int x)->int{
            int res = 0;
            while(nums > 0){
                res += nums % 10;
                nums /= 10;
            }
            return res;
        };
        unordered_map<int,int> parent;
        int n = nums.size();
        vector<pair<int,int>> last_num(n);
        for(int i = 0; i < n; i++){
            last_num[i].first = nums[i];
            last_num[i].second = NumAdd(nums[i]);
            parent[last_num[i].second] = last_num[i].second;
        }    

        sort(last_num.begin(),last_num.end(),[&](const pair<int,int>& a,const pair<int,int>& b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        auto find = [&](this auto&& find,int x)->int{
            if(x == parent[x]){
                return parent[x];
            }
            parent[x] = find(parent[x]);
            return parent[x];
        };

        auto Union = [&](int a,int b)->void{
            parent[find(a)] = find(b);
        }

        for(int i = 0; i < n; i++){
            auto [_,j] = last_num[i];
            if(find(i) != find(j)){
                Union(i,j);
            }
        }

        unordered_map<int,int> cnt;
        for(auto& [_,q] : parent){
            cnt[q]++;
        }
        int res = 0;
        for(auto& [_,q] : cnt){
            res += (q - 1);
        }
        return res;
    }
};