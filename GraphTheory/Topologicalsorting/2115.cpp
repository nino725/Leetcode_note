/*
你有 n 道不同菜的信息。给你一个字符串数组 recipes 和一个二维字符串数组 ingredients 。第 i 道菜的名字为 recipes[i] ，如果你有它 所有 的原材料 ingredients[i] ，那么你可以 做出 这道菜。一份食谱也可以是 其它 食谱的原料，也就是说 ingredients[i] 可能包含 recipes 中另一个字符串。

同时给你一个字符串数组 supplies ，它包含你初始时拥有的所有原材料，每一种原材料你都有无限多。

请你返回你可以做出的所有菜。你可以以 任意顺序 返回它们。

注意两道菜在它们的原材料中可能互相包含。
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
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_map<string, int> zero;
        unordered_map<string, vector<string>> g;
        int n = recipes.size();
        for (int i = 0; i < n; i++) {
            string rec = recipes[i];
            for (auto& s : ingredients[i]) {
                zero[rec]++;
                g[s].push_back(rec);
            }
        }

        unordered_set<string> has(supplies.begin(), supplies.end());
        queue<string> q;
        for (auto& s : supplies) {
            q.push(s);
        }

        vector<string> ans;
        while (!q.empty()) {
            string x = q.front();
            q.pop();
            if (zero.count(x)) {
                ans.push_back(x);
            }
            for (auto c : g[x]) {
                zero[c]--;
                if (zero[c] == 0) {
                    q.push(c);
                }
            }
        }
        return ans;
    }
};