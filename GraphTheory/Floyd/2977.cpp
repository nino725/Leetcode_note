/*
给你两个下标从 0 开始的字符串 source 和 target ，它们的长度均为 n 并且由 小写 英文字母组成。

另给你两个下标从 0 开始的字符串数组 original 和 changed ，以及一个整数数组 cost ，其中 cost[i] 代表将字符串 original[i] 更改为字符串 changed[i] 的成本。

你从字符串 source 开始。在一次操作中，如果 存在 任意 下标 j 满足 cost[j] == z  、original[j] == x 以及 changed[j] == y ，你就可以选择字符串中的 子串 x 并以 z 的成本将其更改为 y 。 你可以执行 任意数量 的操作，但是任两次操作必须满足 以下两个 条件 之一 ：

在两次操作中选择的子串分别是 source[a..b] 和 source[c..d] ，满足 b < c  或 d < a 。换句话说，两次操作中选择的下标 不相交 。
在两次操作中选择的子串分别是 source[a..b] 和 source[c..d] ，满足 a == c 且 b == d 。换句话说，两次操作中选择的下标 相同 。
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

struct node{
    node* son[26]{};
    int sid = -1;
}

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        
        //初始化前缀树
        node* root = new node();
        int sid = 0;
        auto put = [&](string& s)->int{
            node* o = root;
            for(char b : s){
                int i = b - 'a';
                if(o->son[i] == nullptr){
                    o->son[i] = new node();
                } 
                o = o->son[i];
            }

            if(o->sid < 0){
                o->sid = sid++;
            }
            return o->sid;
        };
        
        //初始化距离
        int m = cost.size();
        vector dis(m * 2, vector<int>(m * 2, INT_MAX / 2));
        for(int i = 0; i < m * 2; i++){
            dis[i][i] = 0;
        }
        for(int i = 0; i < m; i++){
            int x = put(original[i]);
            int y = put(changed[i]);
            dis[x][y] = min(dis[x][y], cost[i]);
        }
        
        //构建最短路
        for(int k = 0; k < sid; k++){
            for(int i = 0; i < sid; i++){
                if(dis[i][k] == INT_MAX / 2){
                    continue;
                }
                for(int j = 0; j < sid; j++){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        int n = source.size();
        vector<long long> f(n + 1);
        for(int i = n - 1; i >= 0; i--){
            f[i] = source[i] == target[i] ? f[i + 1] : LLONG_MAX / 2;
            node* p = root;
            node* q = root;
            for(int j = i; j < n; j++){
                p = p->son[source[j] - 'a'];
                q = q->son[target[j] - 'a'];
                if(p == nullptr || q == nullptr){
                    break;
                }
                if(p->sid < 0 || q->sid < 0){
                    continue;
                }

                int d = dis[p->sid][q->sid];
                if(d < INT_MAX / 2){
                    f[i] = min(f[i], dis[p->sid][q->sid] + f[j + 1]);
                }
            }
        }
        return f[0] < LLONG_MAX / 2 ? f[0] : -1;
    }
};