/*
给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。

测试用例保证结果在 32 位有符号整数范围内。
*/

//注意处理状态转移方程和边界

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

class Solution {
public:
    vector<vector<unsigned>> memo;
    int m,n;

    int dfs(string& s, string& t, int i, int j){
        if(i == m){
            return 0;
        }
        if(j == n){
            return 1;
        }
        auto& res = memo[i][j];
        if(res != -1){
            return res;
        }
        if(s[i] == t[j]){
            res = dfs(s,t,i+1,j+1) + dfs(s,t,i+1,j);
        }else{
            res = dfs(s,t,i+1,j);
        }
        return res;
    }

    int numDistinct(string s, string t) {
        m = s.size(), n = t.size();
        memo = vector<vector<unsigned>>(m,vector<unsigned>(n,-1));
        return dfs(s,t,0,0);
    }
};


//记忆化搜索
class Solution {
public:
    vector<vector<unsigned>> memo;
    int m,n;

    int dfs(string& s, string& t, int i, int j){
        if(i == m && j == n){
            return 1;
        }
        if(i == m){
            return 0;
        }
        if(j == n){
            return 1;
        }
        auto& res = memo[i][j];
        if(res != -1){
            return res;
        }
        if(s[i] == t[j]){
            res = dfs(s,t,i+1,j+1) + dfs(s,t,i+1,j);
        }else{
            res = dfs(s,t,i+1,j);
        }
        return res;
    }

    int numDistinct(string s, string t) {
        m = s.size(), n = t.size();
        memo = vector<vector<unsigned>>(m,vector<unsigned>(n,-1));
        return dfs(s,t,0,0);
    }
};