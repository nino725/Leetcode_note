/*
给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称 (name)，其余元素是 emails 表示该账户的邮箱地址。

现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。

合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是 按字符 ASCII 顺序排列 的邮箱地址。账户本身可以以 任意顺序 返回。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unoedered_map>

using namespace std;

int main() {
    
    return 0;
}

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int m = accounts.size();
        unordered_map<string,int> vis; 
        vector<vector<string> G(m);
        for(auto& e : accounts){
            int n = e.size();
            for(int i = 1; i < n - 1; i++){
                int x = e[i], y = e[i + 1];
                vis[x] = 0, vis[y] = 0;
                G[x].push_back(y);
                G[y].push_back(x);
            }
        }

        vector<string> ans;
        auto dfs = [&](this auto&& dfs,string& x)->void{
            vis[x] = 1;
            ans.push_back(x);
            for(auto& p : G[x]){
                if(vis[p] == 0){
                    dfs(p);
                }
            }
        };

        vector<vector<string> res;
        for(int i = 0; i < m; i++){
            ans.clear();
            if(vis[accounts[i][1]] == 0){
                ans.push_back(accounts[i][0]);
                dfs(accounts[i][1]);
                res.push_back(ans);
            }
        }
        return res;
    }
};