#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

/*
给你一个下标从 0 开始的字符串 s 和一个单词字典 dictionary 。你需要将 s 分割成若干个 互不重叠 的子字符串，每个子字符串都在 dictionary 中出现过。s 中可能会有一些 额外的字符 不在任何子字符串中。

请你采取最优策略分割 s ，使剩下的字符 最少 。
*/

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> cnt(dictionary.begin(),dictionary.end());
        auto isTrue = [&](int l, int r)->bool{
            string str = "";
            for(int i = l; i <= r; i++){
                str += s[i];
            }
            return cnt.count(str);
        };

        int n = s.size();
        vector<int> memo(n + 1, INT_MAX);
        auto dfs = [&](this auto&& dfs, int i)->int{
            if(i < 0){
                return 0;
            }
            int& res = memo[i];
            if(res != INT_MAX){
                return res;
            }
            for(int j = i; j >= 0; j--){
                if(isTrue(j,i)){
                    res = min(res, dfs(j - 1));
                }
            }
            res = min(res, dfs(i - 1) + 1);
            return res;
        };
        return dfs(n - 1);
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> cnt(dictionary.begin(),dictionary.end());
        auto isTrue = [&](int l, int r)->bool{
            string str = "";
            for(int i = l; i <= r; i++){
                str += s[i];
            }
            return cnt.count(str);
        };

        int n = s.size();
        vector<int> f(n + 1);
        for(int i = 0; i < n; i++){
            f[i + 1] = f[i] + 1;
            for(int j = 0; j <= i; j++){
                if(isTrue(j,i)){
                    f[i+1] = min(f[i+1], f[j]);
                }
            }
        }
        return f[n];
    }
};