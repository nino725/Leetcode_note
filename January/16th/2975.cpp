#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    
    return 0;
}

/*有一个大型的 (m - 1) x (n - 1) 矩形田地，其两个对角分别是 (1, 1) 和 (m, n) ，田地内部有一些水平栅栏和垂直栅栏，分别由数组 hFences 和 vFences 给出。

水平栅栏为坐标 (hFences[i], 1) 到 (hFences[i], n)，垂直栅栏为坐标 (1, vFences[i]) 到 (m, vFences[i]) 。

返回通过 移除 一些栅栏（可能不移除）所能形成的最大面积的 正方形 田地的面积，或者如果无法形成正方形田地则返回 -1。

由于答案可能很大，所以请返回结果对 109 + 7 取余 后的值。

注意：田地外围两个水平栅栏（坐标 (1, 1) 到 (1, n) 和坐标 (m, 1) 到 (m, n) ）以及两个垂直栅栏（坐标 (1, 1) 到 (m, 1) 和坐标 (1, n) 到 (m, n) ）所包围。这些栅栏 不能 被移除。
*/

class Solution {
public:
    unordered_set<int> f(vector<int>& a, int mx){
        a.push_back(1);
        a.push_back(mx);
        ranges::sort(a);

        unordered_set<int> st;
        for(int i = 0; i < a.size(); i++){
            for(int j = i + 1; i < a.size(); j++){
                st.insert(a[j] - a[i]);
            }
        }
        return st;
    }

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        constexpr int MOD = 1'000'000'007;
        unordered_set<int> h_set = f(hFences,m);
        unordered_set<int> v_set = f(vFences,n);

        int ans = 0;
        for(int x : h_set){
            if(v_set.contains(x)){
                ans = max(ans,x);
            }
        }
        return ans ? 1LL*ans*ans % MOD : -1;
    }
};