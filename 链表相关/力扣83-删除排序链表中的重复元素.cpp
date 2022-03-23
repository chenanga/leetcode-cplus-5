#include<iostream>
#include "myListNode.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == NULL) return NULL;
        ListNode* dummyNode = new ListNode(-101);
        dummyNode->next = head;

        ListNode* pre = head;
        ListNode* cur = head;

        int curVal = cur->val;
        while (cur != NULL) {

            if (curVal != cur->val) {
                pre->next = cur;
                pre = cur;
                curVal = cur->val;
            }
            cur = cur->next;

        }
        pre->next = NULL;
        return dummyNode->next;
    }
};
// //����һЩС�Ż�������һ��Ԫ�غ���һ��Ԫ����ͬʱ��ֱ�ӵ�����������ำֵ
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {

//         if(head == NULL) return NULL;
//         ListNode* dummyNode = new ListNode(-101);
//         dummyNode->next = head;
//         int index1 = 0, index2 = 0;
//         ListNode* pre = head;
//         ListNode* cur = head;

//         int curVal = cur->val;
//         while (cur != NULL){


//             if(curVal != cur->val && index2 != index1){
//                 pre->next = cur;
//                 pre = cur;
//                 curVal = cur->val;
//                 index1 = index2;
//                 index2++;
//             }
//             else if (curVal != cur->val){
//                 pre = cur;
//                 curVal = cur->val;
//                 index2++;

//             }
//             cur = cur->next;
//             index1++;
//         }
//         pre->next = NULL;
//         return dummyNode->next;
//     }
// };

int main() {

	system("pause");
	return 0;
}