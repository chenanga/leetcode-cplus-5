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

        //���k�Ƚϴ󣬻ᳬʱ�������ȱ���һ���б��õ�����
        int len = 0;
        while (head != NULL) {
            head = head->next;
            len++;
        }
        head = dummyNode->next;
        if (k % len == 0) return head; //��ʱ�൱��ѭ��������
        k = k % len;


        ListNode* left = dummyNode;
        ListNode* right = dummyNode;

        //˫�����и�Ϊ���룬
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
        //��ʱcurָ��գ�preָ�����һ��

        pre->next = dummyNode->next;
        delete dummyNode;
        return head2;

    }
};





int main() {

    system("pause");
    return 0;
}