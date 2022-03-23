
#include<iostream>
#include"myListNode.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode* dummyNode = new ListNode(-101);
        dummyNode->next = head;
        ListNode* pre = dummyNode;
        ListNode* cur = head;
        ListNode* succ = head->next;
        int value = -101;
        while (succ != NULL) {
            if (cur->val == succ->val || cur->val == value) {

                value = cur->val;
                cur = succ;
                succ = succ->next;
            }
            else {

                pre->next = cur;
                pre = cur;
                cur = cur->next;
                succ = succ->next;

            }
        }
        if (cur->val != value) //����������һ��֮ǰ�ļ��������ظ����֣���ʱ��ǰ��ƴ������
            pre->next = cur;
        else
            pre->next = NULL;  //�����󼸸����ظ����֣���preָ��NULL;

        ListNode* ret = dummyNode->next;
        delete dummyNode;
        return ret;
    }
};
////�ٷ�д��
//class Solution {
//public:
//    ListNode* deleteDuplicates(ListNode* head) {
//        if (head == NULL) return NULL;
//
//        ListNode* dummyNode = new ListNode(-101);
//        dummyNode->next = head;
//        ListNode* cur = dummyNode;
//
//
//        while (cur->next && cur->next->next) {
//            if (cur->next->val == cur->next->next->val) {
//                int value = cur->next->val;
//
//                while (cur->next && cur->next->val == value) {
//                    cur->next = cur->next->next;
//                }
//
//
//            }
//            else {
//                cur = cur->next;
//
//
//            }
//        }
//
//
//        ListNode* ret = dummyNode->next;
//        delete dummyNode;
//        return ret;
//    }
//};
int main() {

    system("pause");
    return 0;
}