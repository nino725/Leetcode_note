/*
在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示。一次 移动 定义为选择 0 与一个相邻的数字（上下左右）进行交换.

最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。

给出一个谜板的初始状态 board ，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。
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
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> g(6);
        g[0] = {1,3};
        g[1] = {0,2,4};     
        g[2] = {1,5};    
        g[3] = {0,4};
        g[4] = {1,3,5};    
        g[5] = {2,4};
        
        unordered_map<string,int> dis;
        string start = "";
        for(auto& p : board){
            for(int& q : p){
                start += '0' + q;
            }
        }
        if(start == "123450"){
            return 0;
        }

        dis[start] = 0;
        queue<string> q;
        q.push(start);

        auto loc = [&](const string& str)->int{
            for(int i = 0; i < 6; i++){
                if(str[i] == '0'){
                    return i;
                }
            }
            return -1;
        };

        auto swap = [&](string str, int i, int j)->string{
            char c = str[i];
            str[i] = str[j];
            str[j] = c;
            return str;
        };

        while(!q.empty()){
            string x = q.front();
            q.pop();
            int cnt = loc(x);
            for(int& p : g[cnt]){
                string ss = swap(x,cnt,p);
                if(!dis.count(ss)){
                    dis[ss] = dis[x] + 1;
                    if(ss == "123450"){
                        return dis[ss];
                    }
                    q.push(ss);
                }
            }
        }
        return -1;
    }
};