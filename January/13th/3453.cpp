/*

给你一个二维整数数组 squares ，其中 squares[i] = [xi, yi, li] 表示一个与 x 轴平行的正方形的左下角坐标和正方形的边长。

找到一个最小的 y 坐标，它对应一条水平线，该线需要满足它以上正方形的总面积 等于 该线以下正方形的总面积。

答案如果与实际答案的误差在 10-5 以内，将视为正确答案。

注意：正方形 可能会 重叠。重叠区域应该被 多次计数 。*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long total;
    bool check(vector<vector<int>>& squares, double now_y){
        double area = 0;
        for(auto& s : squares){
            double y = s[1];
            if(y < now_y){
                double l = s[2];
                area += l * min(now_y - y, l);
            }
        }
        return area >= total / 2.0;
    }

    double separateSquares(vector<vector<int>>& squares) {
        total = 0;
        int max_y = 0;
        for(auto& s : squares){
            total += 1LL * s[2] * s[2];
            max_y = max(max_y, s[1]+s[2]);
        }
        double l = 0, r = max_y;
        for(int i = 0; i < 47; i++){
            double mid = (l + r) / 2;
            (check(squares, mid) ? r : l) = mid;
        }
        return (l+r) / 2;
    }
};
