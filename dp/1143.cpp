/*
1143. Longest Common Subsequence
Medium
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*  
记忆化搜索
*/
class Solution {
public:
    vector<vector<int>> memo;
    /*改为常量引用传递 降低时间开销 */
    int dfs(const string& text1,const string& text2, int i, int j) {
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }
        int& res = memo[i][j];
        if (res != -1) {
            return res;
        }
        if (text1[i] == text2[j]) {
            res = 1 + dfs(text1, text2, i + 1, j + 1);
        } else {
            res = max(dfs(text1, text2, i + 1, j), dfs(text1, text2, i, j + 1));
        }
        return res;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        memo = vector<vector<int>>(n, vector<int>(m, -1));
        return dfs(text1, text2, 0, 0);
    }
};



/*动态规划，01背包问题的变形*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(text1[i] == text2[j]){
                    dp[i+1][j+1] = dp[i][j] + 1;
                }else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[m][n];
    }
};

/*动态规划，空间优化为一维数组*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text2.size();
        vector<int> dp(n + 1, 0);
        for (char& s : text1) {
            int pre = 0;
            for (int j = 0; j < n; j++) {
                int temp = dp[j + 1];
                dp[j + 1] = s == text2[j] ? pre + 1 : max(dp[j + 1], dp[j]);
                pre = temp;
            }
        }
        return dp[n];
    }
};