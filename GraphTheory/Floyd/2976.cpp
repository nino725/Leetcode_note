/*
给你两个下标从 0 开始的字符串 source 和 target ，它们的长度均为 n 并且由 小写 英文字母组成。

另给你两个下标从 0 开始的字符数组 original 和 changed ，以及一个整数数组 cost ，其中 cost[i] 代表将字符 original[i] 更改为字符 changed[i] 的成本。

你从字符串 source 开始。在一次操作中，如果 存在 任意 下标 j 满足 cost[j] == z  、original[j] == x 以及 changed[j] == y 。你就可以选择字符串中的一个字符 x 并以 z 的成本将其更改为字符 y 。

返回将字符串 source 转换为字符串 target 所需的 最小 成本。如果不可能完成转换，则返回 -1 。

注意，可能存在下标 i 、j 使得 original[j] == original[i] 且 changed[j] == changed[i] 。
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
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = 26;
        const int INF = 0x3f3f3f3f;
        vector dis(n,vector<int>(n,INF));
        for(int i = 0; i < n; i++){
            dis[i][i] = 0;
        }

        int m = original.size();
        for(int i = 0; i < m; i++){
            int x = original[i] - 'a', y = changed[i] - 'a', w = cost[i];
            dis[x][y] = min(dis[x][y] , w);
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                if(dis[i][k] == INF){
                    continue;
                }
                for(int j = 0; j < n; j++){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        long long ans = 0;
        int len = source.size();
        for(int i = 0; i < len; i++){
            int a = source[i] - 'a', b = target[i] - 'a';
            if(dis[a][b] >= 0x3f3f3f3f){
                return -1;
            }
            ans += dis[a][b];
        }
        return ans;
    }
};

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = 26;
        const int INF = 0x3f3f3f3f;
        vector dis(n,vector<int>(n,INF));
        for(int i = 0; i < n; i++){
            dis[i][i] = 0;
        }

        int m = original.size();
        for(int i = 0; i < m; i++){
            int x = original[i] - 'a', y = changed[i] - 'a', w = cost[i];
            dis[x][y] = min(dis[x][y] , w);
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                if(dis[i][k] == INF){
                    continue;
                }
                for(int j = 0; j < n; j++){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        long long ans = 0;
        int len = source.size();
        for(int i = 0; i < len; i++){
            int a = source[i] - 'a', b = target[i] - 'a';
            if(dis[a][b] >= 0x3f3f3f3f){
                return -1;
            }
            ans += dis[a][b];
        }
        return ans;
    }
};