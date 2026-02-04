/*
现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。

例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。
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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> dis(n);
        vector<vector<int>> g(n);
        for(auto& e : prerequisites){
            int x = e[0], y = e[1];
            dis[x]++;
            g[y].push_back(x);
        }      


        queue<int> q;
        for(int i = 0; i < n; i++){
            if(dis[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(int& p : g[x]){
                dis[p]--;
                if(dis[p] == 0){
                    q.push(p);
                }
            }
        }
        if(ans.size() < n){
            return {};
        }
        return ans;

    }
};