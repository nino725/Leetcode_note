/*
对于一个 正整数，如果它和除了它自身以外的所有 正因子 之和相等，我们称它为 「完美数」。

给定一个 整数 n， 如果是完美数，返回 true；否则返回 false。
*/


class Solution {
public:
    bool checkPerfectNumber(int num) {
        int ans = 1;
        if(num == 1){
            return false;
        }
        for(int i = 2; i <= num / i; i++){
            if(num % i == 0){
                ans += i;
            if(i * i != num){
                ans += num / i;
            }
            }
        }
        return ans == num;
    }
};