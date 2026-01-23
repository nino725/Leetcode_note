#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    auto f = [](int a , int b)->int{
        return a + b;
    };

    auto g = [/*捕获外部变量&引用捕获 =值捕获*/](auto a, auto b){
        return a + b;
    };
    cout<<g(10.0,20.0);
    return 0;
}