#include<iostream>
#include"myListNode.h"

using namespace std;

//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//
//        int carry = 0; //进位
//        ListNode* cur1 = l1;
//        ListNode* cur2 = l2;
//        ListNode* sumNodeHead = new ListNode(-1);
//        ListNode* sumNode = sumNodeHead;
//
//        int cur1Val = l1->val;
//        int cur2Val = l2->val;
//
//        while (cur1 != NULL || cur2 != NULL) {
//
//            if (cur1 == NULL)
//                cur1Val = 0;
//            else
//                cur1Val = cur1->val;
//
//            if (cur2 == NULL)
//                cur2Val = 0;
//            else
//                cur2Val = cur2->val;
//
//            sumNode->next = new ListNode((cur1Val + cur2Val + carry) % 10);
//            if (cur1Val + cur2Val + carry > 9)
//                carry = 1;
//            else
//                carry = 0;
//
//            if (cur1 != NULL)
//                cur1 = cur1->next;
//
//            if (cur2 != NULL)
//                cur2 = cur2->next;
//
//            sumNode = sumNode->next;
//
//        }
//        if (carry == 1)
//            sumNode->next = new ListNode(1);
//        return sumNodeHead->next;
//
//
//    }
//};

//依据官方修改的简洁版
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0; //进位
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* sumNodeHead = new ListNode(-1);
        ListNode* sumNode = sumNodeHead;

        int cur1Val = l1->val;
        int cur2Val = l2->val;

        while (cur1 != NULL || cur2 != NULL) {

            int cur1val = cur1 ? cur1->val : 0;
            int cur2val = cur2 ? cur2->val : 0;
            int sum = cur1Val + cur2Val + carry;

            sumNode->next = new ListNode((cur1Val + cur2Val + carry) % 10);
            carry = sum / 10;

            if (cur1 != NULL)
                cur1 = cur1->next;

            if (cur2 != NULL)
                cur2 = cur2->next;

            sumNode = sumNode->next;

        }
        if (carry == 1)
            sumNode->next = new ListNode(1);
        return sumNodeHead->next;

    }
};
int main() {

    int arr1[] = { 9,9,9,9,9,9,9 };
    int arr2[] = { 9,9,9,9 };

    ListNode* l1 = createLinkedList(arr1, sizeof(arr1) / sizeof(int));

    ListNode* l2 = createLinkedList(arr2, sizeof(arr2) / sizeof(int));
    printLinkedList(Solution().addTwoNumbers(l1, l2)) ;
	system("pause");
	return 0;
}