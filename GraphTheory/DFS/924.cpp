/*
给出了一个由 n 个节点组成的网络，用 n × n 个邻接矩阵图 graph 表示。在节点网络中，当 graph[i][j] = 1 时，表示节点 i 能够直接连接到另一个节点 j。 

一些节点 initial 最初被恶意软件感染。只要两个节点直接连接，且其中至少一个节点受到恶意软件的感染，那么两个节点都将被恶意软件感染。这种恶意软件的传播将继续，直到没有更多的节点可以被这种方式感染。

假设 M(initial) 是在恶意软件停止传播之后，整个网络中感染恶意软件的最终节点数。

如果从 initial 中移除某一节点能够最小化 M(initial)， 返回该节点。如果有多个节点满足条件，就返回索引最小的节点。

请注意，如果某个节点已从受感染节点的列表 initial 中删除，它以后仍有可能因恶意软件传播而受到感染。
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
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        unordered_set<int> v(initial.begin(), initial.end());

        vector<bool> vis(n);
        int cnt = 0, flag = 0, num = 0;
        auto dfs = [&](this auto&& dfs, int x) -> void {
            vis[x] = true;
            if (v.count(x)) {
                flag++;
                num = x;
            }
            cnt++;
            for (int i = 0; i < n; i++) {
                if (graph[x][i] == 1 && !vis[i]) {
                    dfs(i);
                }
            }
        };

        int max_cnt = 0, ans = -1;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt = 0, flag = 0;
                dfs(i);
                if (flag == 1) {
                    if (cnt > max_cnt) {
                        max_cnt = cnt;
                        ans = num;
                    } else if (cnt == max_cnt) {
                        if (ans == -1 || num < ans) {
                            ans = num;
                        }
                    }
                }
            }
        }
        return ans == -1 ? ranges::min(initial) : ans;
    }
};