/*
中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。

例如 arr = [2,3,4] 的中位数是 3 。
例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
实现 MedianFinder 类:

MedianFinder() 初始化 MedianFinder 对象。

void addNum(int num) 将数据流中的整数 num 添加到数据结构中。

double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10-5 以内的答案将被接受。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

class MedianFinder {
public:
    priority_queue<int, vector<int>> pre;
    priority_queue<int, vector<int>, greater<>> suf;        
    
    void addNum(int num) {
        if(pre.size() == suf.size()){
            suf.push(num);
            pre.push(suf.top());
            suf.pop();
        }else{
            pre.push(num);
            suf.push(pre.top());
            pre.pop();
        }
    }
    
    double findMedian() {
        if(pre.size() == suf.size()){
            return (1.0*pre.top() + suf.top()) / 2;
        }
        return pre.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */