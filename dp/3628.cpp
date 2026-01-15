#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

/*给你一个由大写英文字母组成的字符串 s。

你可以在字符串的 任意 位置（包括字符串的开头或结尾）最多插入一个 大写英文字母。

返回在 最多插入一个字母 后，字符串中可以形成的 "LCT" 子序列的 最大 数量。

子序列 是从另一个字符串中删除某些字符（可以不删除）且不改变剩余字符顺序后得到的一个 非空 字符串。
*/

/*  分析错误
分析：
有几种方法s变为t，并且可以跳一次
当前字母相同
不能跳
f[i+1][j+1] = f[i][j+1] + f[i][j];

能跳
f[i+1][j+1] = f[i][j+1] + f[i][j] + f[i][j] 跳-- 

当前字母不同

不能跳
f[i+1][j+1] = f[i][j+1]
能跳
f[i+1][j+1] = f[i][j] 跳--
*/

//正确做法

class Solution {
public:
    long long MaxLength(const string& s,const string &t){
        int m = s.length();
        int n = t.size();
        vector<vector<long long>> f(m+1,vector<long long>(n+1,0));
        f[0][0] = 1;
        for(int i = 0; i < m; i++){
            f[i+1][0] = 1;
            for(int j = 0; j < n; j++){
                if(s[i] == t[j]){
                    f[i+1][j+1] = f[i][j] + f[i][j+1];
                }else{
                    f[i+1][j+1] = f[i][j+1];
                }
            }
        }
        return f[m][n];
    }

    long long calcInsertC(string s){
        int cnt_t = ranges::count(s,'T');
        int cnt_l = 0;
        long long res = 0;
        for(char c : s){
            if(c == 'T'){
                cnt_t--;
            }
            if(c == 'L'){
                cnt_l++;
            }
            res = max(res,1LL * cnt_l * cnt_t);
        }
        return res;
    }

    long long numOfSubsequences(string s) {
       long long extra = max({MaxLength(s,"CT"),MaxLength(s,"LC"),calcInsertC(s)});
       return MaxLength(s,"LCT") + extra;
    }
};


//状态机dp
class Solution {
public:
    long long numOfSubsequences(string s) {
        int t = ranges::count(s,'T');
        long long l = 0, lc = 0, lct = 0, c = 0, ct = 0, lt = 0;
        for(char b : s){
            if(b == 'L'){
                l++;
            }else if(b == 'C'){
                lc += l;
                c++;
            }else if(b == 'T'){
                lct += lc;
                ct += c;
                t--;
            }
            lt = max(lt, l * t);
        }
        return lct + max({lc,ct,lt});
    }
};