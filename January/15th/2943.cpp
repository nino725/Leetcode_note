/*
给你两个整数 n 和 m，以及两个整数数组 hBars 和 vBars。网格由 n + 2 条水平线和 m + 2 条竖直线组成，形成 1x1 的单元格。网格中的线条从 1 开始编号。

你可以从 hBars 中 删除 一些水平线条，并从 vBars 中删除一些竖直线条。注意，其他线条是固定的，无法删除。

返回一个整数表示移除一些线条（可以不移除任何线条）后，网格中 正方形空洞的最大面积 。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    
    return 0;
}

class Solution {
public:
    int maxLength(vector<int>& a){
        ranges::sort(a);
        int lenght = 1;
        int ans = 1;
        for(int i = 1; i < a.size(); i++){
            if(a[i] - 1 == a[i-1]){
                lenght++;
                ans = max(ans,lenght);
            }else{
                lenght = 1;
            }
        }
        return ans;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int p = min(maxLength(hBars), maxLength(vBars)) + 1;
        return p * p; 
    }
};


//用set优化
class Solution {
public:
    int maxLong(vector<int>& a){
        int ans  =1;
        unordered_set<int> st(a.begin(),a.end());
        for(int& x : a){
            if(st.contains(x-1)){
                continue;
            }
            int y = x + 1;
            while(st.contains(y)){
                y++;
            }
            ans = max(ans, y - x);
        }
        return ans;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int side = min(maxLong(hBars),maxLong(vBars));
        return side * side;
    }
};