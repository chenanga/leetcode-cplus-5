#include<iostream>
#include"myListNode.h"



using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* cur = head;
        int len = 0;
        while (cur != NULL) {
            len++;
            cur = cur->next;
        }
        for (int sz = 1; sz < len; sz += sz) { //这里sz<len和sz<=len都可以，少一次循环
            ListNode* pre = dummyNode;
            cur = dummyNode->next;
            while (cur != NULL) {
                //使用两个for循环，head1,head2同时往后遍历sz长度，截断。得到两串单链表，合并这两个单链表，返回头
                ListNode* head1 = cur;
                for (int i = 1; i < sz && cur->next != NULL; i++) {
                    cur = cur->next;
                }
                ListNode* head2 = cur->next;
                cur->next = NULL;
                cur = head2;
                if (cur == NULL) cout << "Sz" << sz << endl;
                for (int i = 1; i < sz && cur != NULL && cur->next != NULL; i++) {//加判断条件cur!=NULL,在奇数时候可能会为空
                    cur = cur->next;
                }
                ListNode* next = NULL;
                if (cur != NULL) {
                    next = cur->next;
                    cur->next = NULL;
                }
                ListNode* merged = mergeTwoLists(head1, head2);
                pre->next = merged;
                while (pre->next != NULL) {
                    pre = pre->next;
                }
                cur = next;


            }
        }

        ListNode* ret = dummyNode->next;
        delete dummyNode;
        return ret;
    }
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummyNode = new ListNode(-101);
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* mergeNode = dummyNode;
        while (cur1 && cur2) {

            if (cur1->val <= cur2->val) {
                mergeNode->next = cur1;
                cur1 = cur1->next;
            }
            else { //cur1->val > cur2->val
                mergeNode->next = cur2;
                cur2 = cur2->next;
            }
            mergeNode = mergeNode->next;
        }
        //最多一个不为空
        mergeNode->next = cur1 ? cur1 : cur2;
        ListNode* ret = dummyNode->next;
        delete dummyNode;

        return ret;
    }
};

int main() {

	system("pause");
	return 0;
}