/*
给定一个放有字母和数字的数组，找到最长的子数组，且包含的字母和数字的个数相同。

返回该子数组，若存在多个最长子数组，返回左端点下标值最小的子数组。若不存在这样的数组，返回一个空数组。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    

    return 0;
}

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size();
        int ans[2];
        ans[0] = 0,ans[1] = 0;
        
        int add = 0;
        unordered_map <int,int> cnt;
        cnt[0] = -1;
        for(int i = 0; i < n; i++){
            auto& x = array[i];
            int number = -1;
            if(isdigit(x[0])){
                number = 1;
            }
            add += number;
            if(cnt.contains(add)){
                if(i - cnt[add] > ans[1] - ans[0]){
                    ans[1] = i;
                    ans[0] = cnt[add];
                }
            }else{
                cnt[add] = i;
            }
        }
        if(ans[0] == ans[1]) return {};
         return {array.begin() + ans[0] + 1, array.begin() + ans[1] + 1};
    }
};