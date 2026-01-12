/*
给定两个字符串s1 和 s2，返回 使两个字符串相等所需删除字符的 ASCII 值的最小和 。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s2.size();
        vector<int> f(n + 1, 0);
        int total =
            reduce(s1.begin(), s1.end(), 0) + reduce(s2.begin(), s2.end(), 0);
        for (char& p : s1) {
            for (int j = 0, pre = 0; j < n; j++) {
                int temp = f[j + 1];
                f[j + 1] = p == s2[j] ? pre + p : max(f[j], f[j + 1]);
                pre = temp;
            }
        }
        return total - 2 * f[n];
    }
};