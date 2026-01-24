/*
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。

注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
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
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string, int> hash;
        for (auto& p : wordDict) {
            hash[p]++;
        }
        vector<bool> f(n + 1, false);
        f[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                string temp = "";
                for (int k = j; k <= i; k++) {
                    temp += s[k];
                }
                bool x = hash.count(temp);
                f[i + 1] = f[j] && x;
                if(f[i + 1] == true){
                    break;
                }
            }
        }
        return f[n];
    }
};