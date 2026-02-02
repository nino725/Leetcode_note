/*
中位数是有序序列最中间的那个数。如果序列的长度是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。

例如：

[2,3,4]，中位数是 3
[2,3]，中位数是 (2 + 3) / 2 = 2.5
给你一个数组 nums，有一个长度为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1 位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。
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
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> pre;
        priority_queue<int, vector<int>, greater<>> suf;

        unordered_map<int, int> cnt;

        int pre_size = 0, suf_size = 0;
        auto deleteOld = [&]() -> void {
            while (!pre.empty() && cnt[pre.top()] > 0) {
                cnt[pre.top()]--;
                pre.pop();
            }
            while (!suf.empty() && cnt[suf.top()] > 0) {
                cnt[suf.top()]--;
                suf.pop();
            }
        };

        auto addNum = [&](int x) -> void {
            deleteOld();
            if (pre_size == suf_size) {
                suf.push(x);
                pre.push(suf.top());
                suf.pop();
                pre_size++;
            } else {
                pre.push(x);
                suf.push(pre.top());
                pre.pop();
                suf_size++;
            }
        };

        auto midNum = [&]() -> double {
            deleteOld();
            if (k % 2 == 1) return (double)pre.top();
            return ((long long)pre.top() + suf.top()) / 2.0;
        };

        auto popNum = [&](int x) -> void {
            deleteOld();
            cnt[x]++;
            if (x <= pre.top()) {
                pre_size--;
            } else {
                suf_size--;
            }
        };

        vector<double> res;
        for (int i = 0; i < nums.size(); i++) {
            // 添加
            addNum(nums[i]);
            int left = i - k + 1;
            if (left < 0) {
                continue;
            }

            // 计算
            double ans = midNum();
            res.push_back(ans);

            // 滑出
            popNum(nums[left]);
        }

        return res;
    }
};


//懒删除堆模板
template <typename T, typename Compare = less<T>> class LazyHeap {
    priority_queue<T, vector<T>, Compare> pq;
    unordered_map<T, int> remove_cnt;
    size_t sz = 0;

    void apply_romove() {
        while (!pq.empty() && remove_cnt[pq.top()] > 0) {
            remove_cnt[pq.top()]--;
            pq.pop();
        }
    }

public:
    size_t size() { return sz; }

    void remove(T x) {
        remove_cnt[x]++;
        sz--;
    }

    T top() {
        apply_romove();
        return pq.top();
    }

    T pop() {
        apply_romove();
        sz--;
        T x = pq.top();
        pq.pop();
        return x;
    }

    void push(T x) {
        pq.push(x);
        sz++;
    }

    T push_pop(T x) {
        if (sz > 0 && Compare()(x, top())) {
            pq.push(x);
            x = pq.top();
            pq.pop();
        }
        return x;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> ans(n - k + 1);
        LazyHeap<int> left;
        LazyHeap<int, greater<>> right;

        for (int i = 0; i < n; i++) {
            int in = nums[i];
            if (left.size() == right.size()) {
                left.push(right.push_pop(in));
            } else {
                right.push(left.push_pop(in));
            }

            int l = i - k + 1;
            if (l < 0) {
                continue;
            }

            if (k % 2) {
                ans[l] = left.top();
            } else {
                ans[l] = ((long long)left.top() + right.top()) / 2.0;
            }

            int out = nums[l];
            if (out <= left.top()) {
                left.remove(out);
                if (left.size() < right.size()) {
                    left.push(right.pop());
                }
            } else {
                right.remove(out);
                if (left.size() > right.size() + 1) {
                    right.push(left.pop());
                }
            }
        }
    return ans;
}
};