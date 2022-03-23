#include<iostream>
#include"myListNode.h"
#include<stack>

using namespace std;

//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//
//        stack<int> s1;
//        stack<int> s2;
//        stack<int> sumStack;
//        ListNode* cur1 = l1;
//        ListNode* cur2 = l2;
//        ListNode* res = new ListNode(-1);
//
//        while (cur1 != NULL) {
//            s1.push(cur1->val);
//            cur1 = cur1->next;
//        }
//        while (cur2 != NULL) {
//            s2.push(cur2->val);
//            cur2 = cur2->next;
//        }
//        int carry = 0;
//        while (!s1.empty() || !s2.empty()) {
//
//            int num1 = !s1.empty() ? s1.top() : 0;
//            int num2 = !s2.empty() ? s2.top() : 0;
//            int sum = carry + num1 + num2;
//            sumStack.push(sum % 10);
//            carry = sum / 10;
//            if (!s1.empty()) s1.pop();
//            if (!s2.empty()) s2.pop();
//
//
//        }
//        if (carry == 1)
//            sumStack.push(1);
//        cur1 = res;
//        while (!sumStack.empty()) {
//            cur1->next = new ListNode(sumStack.top());
//            sumStack.pop();
//            cur1 = cur1->next;
//        }
//        return res->next;
//
//    }
//};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<int> s1;
        stack<int> s2;

        ListNode* cur = l1;



        while (cur != NULL) {
            s1.push(cur->val);
            cur = cur->next;
        }
        cur = l2;
        while (cur != NULL) {
            s2.push(cur->val);
            cur = cur->next;
        }
        int carry = 0;

        ListNode* pre = NULL;
        while (!s1.empty() || !s2.empty()) {

            int num1 = !s1.empty() ? s1.top() : 0;
            int num2 = !s2.empty() ? s2.top() : 0;
            int sum = carry + num1 + num2;
            carry = sum / 10;
            cur = new ListNode(sum % 10);
            cur->next = pre;
            pre = cur;
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();

        }
        if (carry == 1) {
            cur = new ListNode(1);
            cur->next = pre;
        }

        return cur;

    }
};
int main() {

	system("pause");
	return 0;
}