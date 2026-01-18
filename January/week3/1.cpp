#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0;
        int c = 0;
        for(char& ch : s){
            if(ch <= 'z' && ch >= 'a'){
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                    v++;
                }else{
                    c++;
                }
            }
        }
        return c == 0 ? 0 : v / c;
    }
};