#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,-1);
        stack<int> l;
        stack<int> r;

        //先找到每个元素的左边
        for(int i = 0; i < n; i++){
            int h = heights[i];

            while(!l.empty() && heights[l.top()] >= h){
                l.pop();
            }

            if(!l.empty()){
            left[i] = l.top();

            }

            l.push(i);
        }

        //找右边
        vector<int> right(n, n);
        for(int i = n-1; i >= 0; i--){
            int h = heights[i];

            while(!r.empty() && heights[r.top()] >= h){
                r.pop();
            }
            if(!r.empty()){

            right[i] = r.top();
            }

            r.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix[0].size();
        vector<int> f(n);
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '0'){
                    f[j] = 0;
                }else{
                    f[j]++;
                }
            }
            ans = max(ans,largestRectangleArea(f));
        }
        return ans;
    }
};

int main() {
    
    return 0;
}