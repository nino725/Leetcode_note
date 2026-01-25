/*
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文串。

返回符合要求的 最少分割次数 。
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
    bool isTrue(string& s,int l, int r){
        while(r > l){
            if(s[l] != s[r]){
                return false;
            }
            r--;
            l++;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> memo(n,10000);
        auto f = [&](this auto&& f,int i)->int{
            if(isTrue(s,0,i)){
                return 0;
            }
            int& res = memo[i];
            if(res != 10000){
                return res;
            }
            
            for(int l = 1; l <= i; l++){
                if(isTrue(s,l,i))
                res = min(res,f(l-1) + 1);
            }
            return res;
        };
        return f(n-1);
    }
};

//转换为递推
class Solution {
public:
    int minCut(string s) {
        auto isTrue = [&](this auto&& isTrue,int l,int r) -> bool{
            if(r <= l){
                return true;
            }
            if(s[l] != s[r]){
                return false;
            }
            return isTrue(l + 1, r - 1);
        };
        int n = s.size();
        vector<int> f(n + 1);
        for(int r = 0; r < n; r++){
            if(isTrue(0,r)){
                continue;
            }
            int temp = INT_MAX;
            for(int l = 1; l <= r; l++){
                if(isTrue(l,r)){
                    temp = min(temp, f[l + 1] + 1);
                }
            }
            f[r] = temp;
        };
        return f[n-1];
    }
};