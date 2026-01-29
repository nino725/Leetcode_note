/*
给你一个有 n 个节点的 有向带权 图，节点编号为 0 到 n - 1 。图中的初始边用数组 edges 表示，其中 edges[i] = [fromi, toi, edgeCosti] 表示从 fromi 到 toi 有一条代价为 edgeCosti 的边。

请你实现一个 Graph 类：

Graph(int n, int[][] edges) 初始化图有 n 个节点，并输入初始边。
addEdge(int[] edge) 向边集中添加一条边，其中 edge = [from, to, edgeCost] 。数据保证添加这条边之前对应的两个节点之间没有有向边。
int shortestPath(int node1, int node2) 返回从节点 node1 到 node2 的路径 最小 代价。如果路径不存在，返回 -1 。一条路径的代价是路径中所有边代价之和。
 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}


//超时
class Graph {
public:
    vector<vector<int>> g;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        g.assign(n,vector<int>(n,INT_MAX / 2));
        for(int i = 0; i < n; i++){
            g[i][i] = 0;
        }
        for(auto& e : edges){
            int x = e[0], y = e[1], wt = e[2];
            g[x][y] = wt;
        }
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]][edge[1]] = edge[2];
    }
    
    int shortestPath(int node1, int node2) {
        vector memo(n,vector(n,vector<int>(n)));
        auto f = [&](this auto&& f, int k, int i, int j)->int{
            if(k < 0){
                return g[i][j];
            }
            auto& res = memo[k][i][j];
            if(res != 0){
                return res;
            }
            return res = min(f(k - 1, i ,j) , f(k - 1, i ,k) + f(k - 1, k , j));
        };
        int x = f(n - 1,node1,node2);
        return x == INT_MAX / 2 ? -1 : x;
    }
};


class Graph {
public:
    const int INT = INT_MAX / 3;
    vector<vector<int>> g;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        g.assign(n,vector<int>(n,INF));
        for(int i = 0; i < n; i++){
            g[i][i] = 0;
        }
        for(auto& e : edges){
            int x = e[0], y = e[1], wt = e[2];
            g[x][y] = wt;
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                if(f[i][k] == INF){
                    continue;
                }
                for(int j = 0; j < n; j++){
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int x = edge[0], y = edge[1], wt = edge[2];
        if(wt >= f[x][y]){
            return;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                f[i][j] = min(f[i][j], f[i][x] + w + f[y][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        int ans = f[node1][node2];
        return ans < INF ? ans : -1;
    }
};
