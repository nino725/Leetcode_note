/*
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。

 
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
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> danger(deadends.begin(), deadends.end());

        string start = "0000";
        if(danger.count(start)){
            return -1;
        }
        unordered_map<string, int> dis;
        dis[start] = 0;
        queue<string> q;
        q.push(start);
        auto recycle = [&](string str, int i, int j)->string{
            char& label = str[i];
            if(j == 0){
                if(label == '0'){
                    label = '9';
                }else{
                    label = label - 1;
                }
            }else{
                if(label == '9'){
                    label = '0';
                }else{
                    label = label + 1;
                }
            }
            return str;
        };
        while(!q.empty()){
            string s = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 2; j++){
                    string p = recycle(s,i,j);
                    if(!dis.count(p) && !danger.count(p)){
                        dis[p] = dis[s] + 1;
                        q.push(p);
                    }
                    if(p == target){
                        return dis[p];
                    }
                }
            }
        }
        return -1;
    }
};