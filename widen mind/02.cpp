/*
实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
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
    int kthToLast(ListNode* head, int k) {
        ListNode* pre = head, *cur = head;
        for(int i = 0; i < k; i++){
            cur = cur->next;
        }while(cur!=nullptr){
            pre=pre->next;
            cur=cur->next;
        }
        return pre->val;
    }
};
