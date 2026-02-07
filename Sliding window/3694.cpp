/*
给你一个由字符 'U'、'D'、'L' 和 'R' 组成的字符串 s，表示在无限的二维笛卡尔网格上的移动。

'U': 从 (x, y) 移动到 (x, y + 1)。
'D': 从 (x, y) 移动到 (x, y - 1)。
'L': 从 (x, y) 移动到 (x - 1, y)。
'R': 从 (x, y) 移动到 (x + 1, y)。
你还得到了一个正整数 k。

你 必须 选择并移除 恰好一个 长度为 k 的连续子字符串 s。然后，从坐标 (0, 0) 开始，按顺序执行剩余的移动。

返回可到达的 不同 最终坐标的数量。
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
    int distinctPoints(string s, int k) {
        int row = 0, col = 0;
        //计算最终位置
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'U'){
                row++;
            }
            if(s[i] == 'D'){
                row--;
            }
            if(s[i] == 'L'){
                col++;
            }
            if(s[i] == 'R'){
                col--;
            }
        }

        set<pair<int,int>> cnt;
        int k_row = 0, k_col = 0;
        for(int r = 0; r < s.size(); r++){
            if(s[r] == 'U'){
                k_row++;
            }
            if(s[r] == 'D'){
                k_row--;
            }
            if(s[r] == 'L'){
                k_col++;
            }
            if(s[r] == 'R'){
                k_col--;
            }
            int l = r - k + 1;
            if(l < 0){
                continue;
            }
            cnt.insert({row - k_row,col - k_col});
            if(s[l] == 'U'){
                k_row--;
            }
            if(s[l] == 'D'){
                k_row++;
            }
            if(s[l] == 'L'){
                k_col--;
            }
            if(s[l] == 'R'){
                k_col++;
            }

        }
        return cnt.size();
    }
};