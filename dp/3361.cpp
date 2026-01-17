/*
给你两个长度相同的字符串 s 和 t ，以及两个整数数组 nextCost 和 previousCost 。

一次操作中，你可以选择 s 中的一个下标 i ，执行以下操作 之一 ：

将 s[i] 切换为字母表中的下一个字母，如果 s[i] == 'z' ，切换后得到 'a' 。操作的代价为 nextCost[j] ，其中 j 表示 s[i] 在字母表中的下标。
将 s[i] 切换为字母表中的上一个字母，如果 s[i] == 'a' ，切换后得到 'z' 。操作的代价为 previousCost[j] ，其中 j 是 s[i] 在字母表中的下标。
切换距离 指的是将字符串 s 变为字符串 t 的 最少 操作代价总和。

请你返回从 s 到 t 的 切换距离 。
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
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        const int SIGMA = 26;

        vector<long long> next(SIGMA * 2 + 1,0);
        vector<long long> pre(SIGMA * 2 + 1,0);

        for(int i = 0; i < SIGMA * 2; i++){
            next[i+1] = nextCost[i % SIGMA] + next[i];
            pre[i+1] = pre[i] + previousCost[i % SIGMA];
        }

        long long ans = 0;
        for(int i = 0; i < t.size(); i++){
            int s_num = s[i] - 'a';
            int t_num = t[i] - 'a';
            ans += min(next[t_num < s_num ? t_num + SIGMA : t_num] - next[s_num],
            pre[(s_num < t_num ? s_num + SIGMA : s_num) + 1] - pre[t_num + 1]);
        }
        return ans;
    }
};