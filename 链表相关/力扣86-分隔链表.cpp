#include<iostream>
#include"myListNode.h"

using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* smallNodeHead = new ListNode(-201);
        ListNode* bigNodeHead = new ListNode(201);

        ListNode* smallNode = smallNodeHead;
        ListNode* bigNode = bigNodeHead;


        ListNode* cur = head;
        while (cur != NULL) {

            if (cur->val < x) {
                smallNode->next = cur;
                smallNode = cur;
            }
            else { // cur->val >= x
                bigNode->next = cur;
                bigNode = cur;
            }
            cur = cur->next;
        }
        bigNode->next = NULL;
        smallNode->next = bigNodeHead->next;

        return smallNodeHead->next;

    }
};

int main() {

	system("pause");
	return 0;
}