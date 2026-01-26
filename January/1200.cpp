#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}


/*
给你个整数数组 arr，其中每个元素都 不相同。

请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。

每对元素对 [a,b] 如下：

a , b 均为数组 arr 中的元素
a < b
b - a 等于 arr 中任意两个元素的最小绝对差
*/


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int flag = INT_MAX;
        int n = arr.size();
        vector<vector<int>> ans;
        for(int i = 1; i < n; i++){
            if(arr[i] - arr[i-1] < flag){
                flag = arr[i] - arr[i-1];
                ans.clear();
            }

            if(arr[i] - arr[i-1] == flag){
                ans.push_back({arr[i-1],arr[i]});
            }

        }      
        return ans;
    }
};