
#include<iostream>
#include"myListNode.h"

using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* dummyHead = new ListNode(-1); //设立头节点
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;    //删除节点
            }
            else
                cur = cur->next;
        }
        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};

int main() {

	system("pause");
	return 0;
}