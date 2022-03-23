#include<iostream>
#include"myListNode.h"

using namespace std;


class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode* slow = dummyNode;
        ListNode* fast = dummyNode;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = slow->next;//�и��������м��п�����123--45  12--34��Ȼ��Ѻ�벿�ַ�ת���ٽ������
        slow->next = NULL;
        head2 = reverseListNode(head2);
        ListNode* cur1 = head;
        ListNode* cur2 = head2;

        while (cur1 != NULL && cur2 != NULL) {
            ListNode* cur1Next = cur1->next;
            ListNode* cur2Next = cur2->next;

            cur1->next = cur2;
            cur2->next = cur1Next;
            cur1 = cur1Next;
            cur2 = cur2Next;
        }

        delete dummyNode;
        return;

    }
private:

    ListNode* reverseListNode(ListNode* head) {

        ListNode* pre = NULL;
        ListNode* cur = head;

        while (cur != NULL) {
            ListNode* next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;

        }
        return pre;
    }
};


int main() {

	system("pause");
	return 0;
}