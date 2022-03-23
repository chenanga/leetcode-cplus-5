#include<iostream>
#include"myListNode.h"

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return head;
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode* pre = dummyNode;
        while (pre->next && pre->next->next ) {
            ListNode* node1 = pre->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;

            node2->next = node1;
            node1->next = next;
            pre->next = node2;

            pre = node1; //��ʱnode1���ڽ�����Ŀ���ģ���next֮ǰ��
        }

        ListNode* ret = dummyNode->next;
        delete dummyNode;

        return ret;
    }
};

int main() {

	system("pause");
	return 0;
}