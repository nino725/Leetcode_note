/*
这里有一个非负整数数组 arr，你最开始位于该数组的起始下标 start 处。当你位于下标 i 处时，你可以跳到 i + arr[i] 或者 i - arr[i]。

请你判断自己是否能够跳到对应元素值为 0 的 任一 下标处。

注意，不管是什么情况下，你都无法跳到数组之外。
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
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector w(n,vector<int>());
        vector<bool> vis_f(n, false);
        auto f = [&](this auto&& f,int start)->void{
            if(vis_f[start]){
                return;
            }
            vis_f[start] = true;
            int left = start - arr[start];
            int right = start + arr[start];
            if(left >= 0){
                w[start].push_back(left);
                f(left);
            }
            if(right < n){
                w[start].push_back(right);
                f(right);
            }
        };
        f(start);

        vector<bool> vis(n,false);
        bool ans = false;
        auto dfs = [&](this auto&& dfs, int start)->void{
            if (vis[start] || ans) return;
            vis[start] = true;
            if(arr[start] == 0){
                ans = true;
            }
            for(int p : w[start]){
                dfs(p);
            }
        };
        dfs(start);
        return ans;

    }
};

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n,false);
        auto dfs = [&](this auto&& dfs,int i)->bool{
            if(i < 0 || i > n - 1 || vis[i]){
                return false;
            }

            if(arr[i] == 0){
                return true;
            }

            vis[i] = true;

            return dfs(i - arr[i]) || dfs(i + arr[i]);
        };
        return dfs(start);
    }
};