/*
给定平面上 n 对 互不相同 的点 points ，其中 points[i] = [xi, yi] 。回旋镖 是由点 (i, j, k) 表示的元组 ，其中 i 和 j 之间的欧式距离和 i 和 k 之间的欧式距离相等（需要考虑元组的顺序）。

返回平面上所有回旋镖的数量。
*/

class Solution {
public:
    int distance(vector<int>& a,vector<int>& b){
        int x = a[0] - b[0];
        int y = a[1] - b[1];
        return x*x + y*y;
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<int,int> cnt;
            for(int j = 0; j < points.size(); j++){
                if(i == j){
                    continue;
                }
                int x = distance(points[i],points[j]);
                cnt[x]++;
                if(cnt[x] >= 2){
                    ans = ans - (cnt[x]-2)*(cnt[x]-1) + (cnt[x]-1)*cnt[x];
                }
            }
        }
        return ans;
    }
};