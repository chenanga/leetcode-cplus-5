#include<iostream>


using namespace std;



 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
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

	system("pause");
	return 0;
}