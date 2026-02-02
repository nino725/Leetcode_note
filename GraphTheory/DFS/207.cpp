/*
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(numCourses);
        for(auto& e : prerequisites){
            int x = e[0], y = e[1];
            G[x].push_back(y);
        }
        
        int v = 0, e = 0;
        vector<bool> vis(numCourses, false);
        auto dfs = [&](this auto&& dfs, int i)->void{
            vis[i] = true;
            e += G[i].size();
            v++;
            for(int& p : G[i]){
                if(!vis[p]){
                    dfs(p);
                }
            }
        };

        for(int i = 0; i < numCourses; i++){
            if(vis[i] == false){
                v = 0;
                e = 0;
                dfs(i);
                if(2 * v == e){
                    return false;
                }
            }
        }
        return true;
    }
};

//有向图判环(三色标记法)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //1.建图
        vector<vector<int>> G(numCourses);
        for(auto& e : prerequisites){
            int x = e[0], y = e[1];
            G[x].push_back(y);
        }

        //2.创建初始值
        vector<int> color(numCourses);

        auto dfs = [&](this auto&& dfs,int x)->bool{
            color[x] = 1;
            for(int& p : G[x]){
                if(color[p] == 1){
                    return true;
                }else if(color[p] == 0){
                    if(dfs(p)){
                        return true;
                    }
                }
            }
            color[x] = 2;
            return false;
        };

        for(int i = 0; i < numCourses; i++){
            if(color[i] == 0){
                if(dfs(i)){
                    return false;
                }
            }
        }
        return true;
    }
};