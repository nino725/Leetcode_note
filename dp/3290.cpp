#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

/*给你一个大小为 4 的整数数组 a 和一个大小 至少为 4 的整数数组 b。

你需要从数组 b 中选择四个下标 i0, i1, i2, 和 i3，并满足 i0 < i1 < i2 < i3。你的得分将是 a[0] * b[i0] + a[1] * b[i1] + a[2] * b[i2] + a[3] * b[i3] 的值。

返回你能够获得的 最大 得分。*/


//记忆化搜索
class Solution {
public:
    vector<vector<long long>> memo;
    int m;
    
    long long dfs(vector<int>& a, vector<int>& b, int i, int j){
        if(i == 4){
            return 0;
        }
        if(j == m){
            return LLONG_MIN / 2;
        }
        long long &res = memo[i][j];
        if(res != LLONG_MIN / 2){
            return res;
        }
        return res = max(dfs(a,b,i,j+1), dfs(a,b,i+1,j+1) + (long long)a[i] * b[j]); 
    }

    long long maxScore(vector<int>& a, vector<int>& b) {
        m = b.size();
        memo = vector<vector<long long>>(4,vector<long long>(m,LLONG_MIN / 2));
        return dfs(a,b,0,0);
    }
};

//关键：分析状态转移方程和递归边界
class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int m = b.size();
        vector<vector<long long>> f(5,vector<long long>(m+1,0));
        for(int i = 1; i < 5; i++){
            f[i][0] = LLONG_MIN/2;
        }
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < m; j++){
                f[i+1][j+1] = max(f[i+1][j],f[i][j] + (long long)a[i]*b[j]);
            }
        }
        return f[4][m];
    }
};