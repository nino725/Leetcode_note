#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
*/

/*第一种记忆化搜索
插入一个字符 i不变，j向前
删除一个字符i向前，j不变
替换一个字符都向前，操作数加一
*/
class Solution {
public:
    vector<vector<int>> memo;
    int n, m;

    int dfs(string& word1, string& word2, int i, int j){
        if(i<0){
            return j + 1;
        }
        if(j < 0){
            return i + 1;
        }
        int& res = memo[i][j];
        if(res != -1){
            return res;
        }
        if(word1[i] == word2[j]){
            res = dfs(word1,word2,i-1,j-1);
        }else{
            res = min({dfs(word1,word2,i,j-1),dfs(word1,word2,i-1,j),dfs(word1,word2,i-1,j-1)}) + 1;
        }
        return res;
    }

    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        memo = vector<vector<int>>(n,vector<int>(m,-1));
        return dfs(word1,word2,n-1,m-1);
    }
};


/*二维数组dp*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> f(n+1,vector<int>(m+1,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(word1[i] == word2[j]){
                    f[i+1][j+1] = f[i][j];
                }else{
                    f[i+1][j+1] = min({f[i][j+1],f[i+1][j],f[i][j]})+1;
                }
            }
        }
        return f[n][m];
    }
};

/*空间优化*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word2.length();
        vector<int> f(m+1);
        for(int j = 0; j < m; j++){
            f[j+1] = j+1;
        }
        for(char& s : word1){
            int pre = f[0];
            f[0]++;
            for(int j = 0; j < m; j++){
                int tem = f[j+1];
                f[j+1] = s == word2[j] ? pre : min({tem,f[j],pre}) + 1;
                pre = tem;
            }
        }
        return f[m];
    }
};