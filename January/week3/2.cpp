#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    
    return 0;
}

//�ᳬʱ

class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        int max_cap = 0;
        for(int i = 0; i < n; i++){
            int& x = costs[i];
            for(int j = i + 1; j < n; j++){
                if(costs[j] >= budget - x){
                    continue;
                }
                max_cap = max(max_cap, capacity[i] + capacity[j]);
            }
            if(x < budget){
                max_cap = max(max_cap, capacity[i]);
            }
        }
        return max_cap;
    }
};