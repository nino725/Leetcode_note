/*
给你一个字符串 initialCurrency，表示初始货币类型，并且你一开始拥有 1.0 单位的 initialCurrency。

另给你四个数组，分别表示货币对（字符串）和汇率（实数）：

pairs1[i] = [startCurrencyi, targetCurrencyi] 表示在 第 1 天，可以按照汇率 rates1[i] 将 startCurrencyi 转换为 targetCurrencyi。
pairs2[i] = [startCurrencyi, targetCurrencyi] 表示在 第 2 天，可以按照汇率 rates2[i] 将 startCurrencyi 转换为 targetCurrencyi。
此外，每种 targetCurrency 都可以以汇率 1 / rate 转换回对应的 startCurrency。
你可以在 第 1 天 使用 rates1 进行任意次数的兑换（包括 0 次），然后在 第 2 天 使用 rates2 再进行任意次数的兑换（包括 0 次）。

返回在两天兑换后，最大可能拥有的 initialCurrency 的数量。

注意：汇率是有效的，并且第 1 天和第 2 天的汇率之间相互独立，不会产生矛盾。
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
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        auto cal_amount = [&](vector<vector<string>>& pairs, vector<double>& rates){
            int n = pairs.size();
            unordered_map<string,vector<pair<string,double>>> g;
            for(int i = 0; i < n; i++){
                string a = pairs[i][0], b = pairs[i][1];
                g[a].push_back({b,rates[i]});
                g[b].push_back({a,1 / rates[i]});
            }

            unordered_map<string, double> amount;
            auto dfs = [&](this auto&& dfs, string& x, double cur_amount)->void{
                amount[x] = cur_amount;
                for(auto& [to, rate] : g[x]){
                    if(!amount.count(to)){
                        dfs(to, rate * cur_amount);
                    }
                }
            };
            dfs(initialCurrency, 1);
            return amount;
        };

        auto firstDay = cal_amount(pairs1, rates1);
        auto secondDay = cal_amount(pairs2, rates2);

        double ans = 0;
        for(auto& [x,a] : secondDay){
            ans = max(ans, firstDay[x] / a);
        }
        return ans;
        
    }
};

class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string,vector<pair<string,double>>> g;
        double ans = 1.0;

        int n = pairs1.size();
        for(int i = 0; i < n; i++){
            string x = pairs1[i][0], y = pairs1[i][1];
            g[x].push_back({y,rates1[i]});
            g[y].push_back({x,1 / rates1[i]});
        }

        for(const auto& [s,_] : g){
            g[s].push_back({s + "2", 1.0});
        }

        n = pairs2.size();
        for(int i = 0; i < n; i++){
            string x = pairs2[i][0] + "2";
            string y = pairs2[i][1] + "2";
            g[x].push_back({y,rates2[i]});
            g[y].push_back({x,1 / rates2[i]});
        }

        auto dfs = [&](this auto&& dfs,string x , string pre, double curAmount){
            if(x == initialCurrency + "2"){
                ans = max(ans,curAmount);
                return;
            }
            for(const auto& [to,rate] : g[x]){
                if(to != pre){
                    dfs(to,x,curAmount*rate);
                }
            }
        };
        dfs(initialCurrency, "", 1.0);
        return ans;
    }
};