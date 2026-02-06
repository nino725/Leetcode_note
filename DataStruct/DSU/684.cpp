/*
树可以看成是一个连通且 无环 的 无向 图。

给定一个图，该图从一棵 n 个节点 (节点值 1～n) 的树中添加一条边后获得。添加的边的两个不同顶点编号在 1 到 n 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。

请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的那个。

 
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i = 1; i < n+1; i++){
            parent[i] = i;
        }
        auto find = [&](this auto&& find,int x)->int{
            if(x == parent[x]){
                return parent[x];
            }else{
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        auto Union = [&](int i, int j){
            parent[find(i)] = find(j);
        };

        for(auto& e : edges){
            int x = e[0], y = e[1];
            if(find(x) != find(y)){
                Union(x,y);
            }else{
                return e;
            }
        }
        return {};
    }
};