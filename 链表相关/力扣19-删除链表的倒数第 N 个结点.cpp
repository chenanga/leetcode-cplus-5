#include<iostream>
#include"myListNode.h"

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode* left = dummyNode;
        ListNode* right = dummyNode;
        for (int i = 0; i < n + 1; i++) { //left��Ҫ����ɾ���ڵ�ǰ��,����right��Ҫ��n-1
            right = right->next;
        }

        while (right != NULL) {
            //left��rightͬʱ�ƶ�
            right = right->next;
            left = left->next;
        }
        ListNode* del = left->next;
        left->next = del->next;
        delete del;

        ListNode* ret = dummyNode->next;
        delete dummyNode;
        return ret;
    }
};

int main() {

	system("pause");
	return 0;
}