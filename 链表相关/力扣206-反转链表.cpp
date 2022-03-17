#include<iostream>

#include "myListNode.h"
using namespace std;



 //Definition for singly-linked list.

//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {
//        if (head == NULL) return NULL;
//        ListNode* pre = NULL;
//        ListNode* cur = head;
//        ListNode* next = head->next;
//        while (cur != NULL) {
//            cur->next = pre;
//            pre = cur;
//            cur = next;
//            if(next != NULL)
//                next = next->next;
//        }
//        return pre;
//	}
//};
//
//·½·¨2
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
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

    int arr[] = { 1,2,3,4,5 };
    int n = sizeof(arr) / sizeof(int);

    ListNode* head = createLinkedList(arr, n);
    printLinkedList(head);

    ListNode* head2 = Solution().reverseList(head);
    printLinkedList(head2);

    deletLinkedList(head2);


	system("pause");
	return 0;
}