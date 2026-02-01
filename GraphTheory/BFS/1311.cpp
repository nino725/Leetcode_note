/*
有 n 个人，每个人都有一个  0 到 n-1 的唯一 id 。

给你数组 watchedVideos  和 friends ，其中 watchedVideos[i]  和 friends[i] 分别表示 id = i 的人观看过的视频列表和他的好友列表。

Level 1 的视频包含所有你好友观看过的视频，level 2 的视频包含所有你好友的好友观看过的视频，以此类推。一般的，Level 为 k 的视频包含所有从你出发，最短距离为 k 的好友观看过的视频。

给定你的 id  和一个 level 值，请你找出所有指定 level 的视频，并将它们按观看频率升序返回。如果有频率相同的视频，请将它们按字母顺序从小到大排列。
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
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();

        queue<int> q;
        vector<int> dis(n,-1);
        dis[id] = 0;
        q.push(id);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int& p : friends[x]){
                if(dis[p] < 0){
                    dis[p] = dis[x] + 1;
                    q.push(p);
                }
            }
        };

        unordered_map<string,int> cnt;
        for(int i = 0; i < n; i++){
            if(dis[i] == level){
                for(auto& p : watchedVideos[i]){
                    cnt[p]++;
                   
                }
            }
        }

        vector<pair<string, int>> fre(cnt.begin(), cnt.end());

        sort(fre.begin(), fre.end(), [](const pair<string,int> &a, const pair<string, int>& b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second < b.second;
        });

        vector<string> ans;
        for(auto& p : fre){
            ans.push_back(p.first);
        }
        return ans;
    }
};