/*
给你一个整数数组 arr 和一个整数 k ，其中数组长度是偶数，值为 n 。

现在需要把数组恰好分成 n / 2 对，以使每对数字的和都能够被 k 整除。

如果存在这样的分法，请返回 true ；否则，返回 false。

 
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
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> cnt;
        for(int& x : arr){
            x = (x % k + k) % k;
            cnt[x]++;
        }
        for(int& p : arr){
            p = (p % k + k) % k;
            if(cnt.contains(p)){
                cnt[p]--;
                if(cnt[p] == 0){
                    cnt.erase(p);
                }
                int k_p = p == 0 ? 0 : k - p;
                if(!cnt.contains(k_p)){
                    return false;
                }
                cnt[k_p]--;
                if(cnt[k_p] == 0){
                    cnt.erase(k_p);
                }
            }
        }
        return true;
    }
};