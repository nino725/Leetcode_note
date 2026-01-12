/* 583. Delete Operation for Two Strings 

给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

每步 可以删除任意一个字符串中的一个字符。

本质和1143一样

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> memo;
    int dfs(const string& word1,const string& word2,int i, int j){
        if(i == word1.size() || j == word2.size()){
            return 0;
        }
        int& res = memo[i][j];
        if(res != -1){
            return res;
        }   
        if(word1[i] == word2[j]){
            res = 1 + dfs(word1, word2, i + 1, j + 1);
        }else{
            res = max(dfs(word1, word2, i + 1, j), dfs(word1, word2, i, j + 1));
        }
        return res;
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        memo = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
        int ans = dfs(word1, word2, 0, 0);
        return m + n - 2 * ans;
    }
};

/*
动态规划dp
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(word1[i] == word2[j]){
                    f[i + 1][j + 1] = f[i][j] + 1;
                }else{
                    f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
                }
            }
        }
        return m + n - 2 * f[m][n];    
    }
};

/*空间优化 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word2.size();
        vector<int> f(m+1,0);
        for(char& x : word1){
            for(int j = 0,pre = 0; j < m; j++){
                int temp = f[j+1];
                f[j+1] = x == word2[j] ? pre + 1 : max(f[j+1],f[j]);
                pre = temp;
            }
        }
        return word1.size() + word2.size() - 2 * f[m];
    }
};