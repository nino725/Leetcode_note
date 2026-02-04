/*
给你一个 有向无环图 ， n 个节点编号为 0 到 n-1 ，以及一个边数组 edges ，其中 edges[i] = [fromi, toi] 表示一条从点  fromi 到点 toi 的有向边。

找到最小的点集使得从这些点出发能到达图中所有点。题目保证解存在且唯一。

你可以以任意顺序返回这些节点编号。
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
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> g(n);
        for(auto& e : edges){
            int x = e[0], y = e[1];
            g[y]++;
        }    

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(g[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};