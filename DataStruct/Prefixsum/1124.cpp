/*
给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。

我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。

所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。

请你返回「表现良好时间段」的最大长度。
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
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int ans = 0;
        vector<int> f(n+1);
        stack<int> st;
        f[0] = 0;
        st.push(0);
        for(int i = 0; i < n; i++){
            f[i + 1] = f[i] + (hours[i] > 8 ? 1 : -1);
            if(f[i] < f[st.top()]){
                st.push(i);
            }
        }
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && f[i+1] > f[st.top()]){
                ans = max(ans, i - st.top() + 1);
                st.pop();
            }
            
        }
        return ans;
    }
};

