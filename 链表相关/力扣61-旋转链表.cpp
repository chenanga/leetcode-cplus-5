#include<iostream>
#include"myListNode.h"

using namespace std;


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        if (k == 0) return head;
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;

        //如果k比较大，会超时，所有先遍历一遍列表，得到长度
        int len = 0;
        while (head != NULL) {
            head = head->next;
            len++;
        }
        head = dummyNode->next;
        if (k % len == 0) return head; //此时相当于循环回来了
        k = k % len;


        ListNode* left = dummyNode;
        ListNode* right = dummyNode;

        //双索引切割为两半，
        for (int i = 0; i < k + 1; i++) {
            if (right == NULL)
                right = dummyNode->next;

            right = right->next;
        }
        while (right != NULL) {
            left = left->next;
            right = right->next;
        }

        ListNode* head2 = left->next;
        left->next = NULL;
        ListNode* cur = head2;
        ListNode* pre = NULL;
        while (cur != NULL) {
            pre = cur;
            cur = cur->next;
        }
        //此时cur指向空，pre指向最后一个

        pre->next = dummyNode->next;
        delete dummyNode;
        return head2;

    }
};





int main() {

    system("pause");
    return 0;
}