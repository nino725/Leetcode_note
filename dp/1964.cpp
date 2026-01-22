/*
你打算构建一些障碍赛跑路线。给你一个 下标从 0 开始 的整数数组 obstacles ，数组长度为 n ，其中 obstacles[i] 表示第 i 个障碍的高度。

对于每个介于 0 和 n - 1 之间（包含 0 和 n - 1）的下标  i ，在满足下述条件的前提下，请你找出 obstacles 能构成的最长障碍路线的长度：

你可以选择下标介于 0 到 i 之间（包含 0 和 i）的任意个障碍。
在这条路线中，必须包含第 i 个障碍。
你必须按障碍在 obstacles 中的 出现顺序 布置这些障碍。
除第一个障碍外，路线中每个障碍的高度都必须和前一个障碍 相同 或者 更高 。
返回长度为 n 的答案数组 ans ，其中 ans[i] 是上面所述的下标 i 对应的最长障碍赛跑路线的长度。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}


//记忆化搜索不能过超时
class Solution {
public:
    vector<int> memo;

    int dfs(vector<int>& obstacles, int i){
        int& res = memo[i];
        if(res != -1){
            return res;
        }
        res = 1;
        for(int j = 0; j < i; j++){
            if(obstacles[j] <= obstacles[i]){
                res = max(res, dfs(obstacles,j) + 1);
            }
        }
        return res;
    }

    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        memo.assign(n,-1);
        vector<int> ans(n,0);
        for(int i = 0; i < n; i++){
            ans[i] = dfs(obstacles,i);
        }
        return ans;
    }
};

class Solution {
public:
    int f(vector<int>& g, int x){
        int left = 0, right = g.size() - 1;
        while(right >= left){
            int mid = left + (right - left) / 2;
            if(g[mid] < x)
            {
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return left;
    }

    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n,0), g;
        for(int i = 0; i < n; i++){
            int& x = obstacles[i];
            int loc = f(g,x + 1);
            ans[i] = loc + 1;
            if(loc >= g.size()){
                g.push_back(x);
            }else{
                g[loc] = x;
            }
        }
        return ans;
    }
};