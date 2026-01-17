#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

/*
在二维平面上存在 n 个矩形。给你两个下标从 0 开始的二维整数数组 bottomLeft 和 topRight，两个数组的大小都是 n x 2 ，其中 bottomLeft[i] 和 topRight[i] 分别代表第 i 个矩形的 左下角 和 右上角 坐标。

我们定义 向右 的方向为 x 轴正半轴（x 坐标增加），向左 的方向为 x 轴负半轴（x 坐标减少）。同样地，定义 向上 的方向为 y 轴正半轴（y 坐标增加），向下 的方向为 y 轴负半轴（y 坐标减少）。

你可以选择一个区域，该区域由两个矩形的 交集 形成。你需要找出能够放入该区域 内 的 最大 正方形面积，并选择最优解。

返回能够放入交集区域的正方形的 最大 可能面积，如果矩形之间不存在任何交集区域，则返回 0。

*/

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int side = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            auto& left_i = bottomLeft[i], right_i = topRight[i];
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                auto& left_j = bottomLeft[j], right_j = topRight[j];
                int row = min(right_i[0],right_j[0]) - max(left_i[0],left_j[0]);
                int col = min(right_i[1],right_j[1]) - max(left_i[1],left_j[1]);
                
                side = min(row,col);
                ans = max(ans,(long long)side*side*1LL);
            }
        }
        return ans;
    }
};