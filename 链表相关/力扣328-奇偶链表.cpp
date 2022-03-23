#include<iostream>
#include"myListNode.h"

using namespace std;


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* firstHead = new ListNode(-1); //第一个节点对应的 奇数/偶数 序列
        ListNode* secondHead = new ListNode(-1);
        ListNode* firstNode = firstHead;
        ListNode* secondNode = secondHead;
        ListNode* cur = head;

        int index = 1;


        while (cur != NULL) {

            if (index % 2 == 1) {
                firstNode->next = cur;
                firstNode = cur;
            }
            else {
                secondNode->next = cur;
                secondNode = cur;
            }
            cur = cur->next;
            index++;
        }
        secondNode->next = NULL;
        firstNode->next = secondHead->next;

        return firstHead->next;

    }
};

int main() {

	system("pause");
	return 0;
}