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
        for (int sz = 1; sz < len; sz += sz) { //����sz<len��sz<=len�����ԣ���һ��ѭ��
            ListNode* pre = dummyNode;
            cur = dummyNode->next;
            while (cur != NULL) {
                //ʹ������forѭ����head1,head2ͬʱ�������sz���ȣ��ضϡ��õ������������ϲ�����������������ͷ
                ListNode* head1 = cur;
                for (int i = 1; i < sz && cur->next != NULL; i++) {
                    cur = cur->next;
                }
                ListNode* head2 = cur->next;
                cur->next = NULL;
                cur = head2;
                if (cur == NULL) cout << "Sz" << sz << endl;
                for (int i = 1; i < sz && cur != NULL && cur->next != NULL; i++) {//���ж�����cur!=NULL,������ʱ����ܻ�Ϊ��
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
        //���һ����Ϊ��
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