/*
基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。

假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。

例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。（变化后的基因必须位于基因库 bank 中）

给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。

注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。
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
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        auto diff = [&](const string& a, const string& b)->bool{
            int cnt = 0;
            for(int i = 0; i < 8; i++){
                if(a[i] != b[i]){
                    cnt++;
                }
            }
            return cnt == 1;
        };

        int n = bank.size();
        unordered_map<string,vector<string>> g;
        for(int i = 0; i < n; i++){
            if(diff(startGene, bank[i])){
                string x = startGene, y = bank[i];
                g[x].push_back(y);
                g[y].push_back(x);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(diff(bank[i], bank[j])){
                    string x = bank[i], y = bank[j];
                    g[x].push_back(y);
                    g[y].push_back(x);
                }
            }
        }

        if(!g.count(endGene)){
            return -1;
        }
        unordered_map<string,int> dis;
        dis[startGene] = 0;
        queue<string> q;
        q.push(startGene);
        while(!q.empty()){
            string x = q.front();
            q.pop();
            for(auto& p : g[x]){
                if(!dis.count(p)){
                    dis[p] = dis[x] + 1;
                    q.push(p);
                }
            }
        }
        return dis.count(endGene) ? dis[endGene] : -1;
    }
};