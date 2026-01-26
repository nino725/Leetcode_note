#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

/*
给你一个二进制字符串 s ，你需要将字符串分割成一个或者多个 子字符串  ，使每个子字符串都是 美丽 的。

如果一个字符串满足以下条件，我们称它是 美丽 的：

它不包含前导 0 。
它是 5 的幂的 二进制 表示。
请你返回分割后的子字符串的 最少 数目。如果无法将字符串 s 分割成美丽子字符串，请你返回 -1 。

子字符串是一个字符串中一段连续的字符序列。
*/

class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        auto isTrue = [&](int l, int r){
            if(s[l] == '0'){
                return false;
            }
            int val = 0;
            for(int i = l; i <= r; i++){
                val = val * 2 + (s[i] - '0');
            }
            while (val % 5 == 0) {
                val /= 5;
            }
            return val == 1;
        };

        int n = s.size();
        vector<int> memo(n,-1);
        auto f = [&](this auto&& f,int r)->int{
            if(r < 0){
                return 0;
            }
            int& res = memo[r];
            if(res != -1){
                return res;
            }
            res = 20;
            for(int l = 0; l <= r; l++){
                if(isTrue(l,r)){
                    res = min(res,f(l - 1) + 1);
                }
            }
            return res;
        };
        return f(n-1) == 20 ? -1 : f(n-1);
    }
};


class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        auto isTrue = [&](int l, int r){
            if(s[l] == '0'){
                return false;
            }
            int val = 0;
            for(int i = l; i <= r; i++){
                val = val * 2 + (s[i] - '0');
            }
            while (val % 5 == 0) {
                val /= 5;
            }
            return val == 1;
        };
        int n = s.size();
        vector<int> f(n+1,20);
        f[0] = 0;
        for(int r = 0; r < n; r++){
            for(int l = 0; l <= r; l++){
                if(isTrue(l,r)){
                    f[r+1] = min(f[l] + 1,f[r+1]);
                }
            }
        }
        return f[n] == 20? -1 : f[n];
    }
};