/*
你有一个炸弹需要拆除，时间紧迫！你的情报员会给你一个长度为 n 的 循环 数组 code 以及一个密钥 k 。

为了获得正确的密码，你需要替换掉每一个数字。所有数字会 同时 被替换。

如果 k > 0 ，将第 i 个数字用 接下来 k 个数字之和替换。
如果 k < 0 ，将第 i 个数字用 之前 k 个数字之和替换。
如果 k == 0 ，将第 i 个数字用 0 替换。
由于 code 是循环的， code[n-1] 下一个元素是 code[0] ，且 code[0] 前一个元素是 code[n-1] 。

给你 循环 数组 code 和整数密钥 k ，请你返回解密后的结果来拆除炸弹！
*/

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(k == 0){
            code.assign(n,0);
            return code;
        }

        vector<int> codes(2 * n);
        for(int i = 0; i < n; i++){
            codes[i] = code[i];
            codes[i+n] = code[i];
        }

        if(k > 0){
            int cnt = 0;
            for(int r = 0; r < n + k; r++){
                cnt += codes[r];
                int l = r - k;
                if(l < 0){
                    continue;
                }
                cnt -= codes[l];    
                code[l] = cnt;
            }
        }

        if(k < 0){
            k = -k;
            int cnt = 0;
            for(int r = 2 * n - 1; r >= n - k; r--){
                cnt += codes[r];
                int l = r + k;
                if(l - n >= n){
                    continue;
                }
                cnt -= codes[l];
                code[l - n] = cnt; 
            }
        }
        return code;
    }
};

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        int r = k > 0 ? k + 1 : n;
        k = abs(k);
        
        int s = reduce(code.begin() + r - k, code.begin() + r);

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = s;
            s += code[r % n] - code[(r - k) % n];
            r++;
        }
        return ans;
    }
};