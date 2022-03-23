

#include<iostream>
#include"myListNode.h"

using namespace std;


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

//         ListNode* dummyNode = new ListNode(-101);
//         ListNode* cur1 = list1;
//         ListNode* cur2 = list2;
//         ListNode* mergeNode = dummyNode;
//         while(cur1 || cur2){
//             int cur1Val = cur1 ? cur1->val : 101;
//             int cur2Val = cur2 ? cur2->val : 101;

//             if(cur1Val <= cur2Val && cur1){
//                 mergeNode->next = cur1;
//                 mergeNode = mergeNode->next;
//                 cur1 = cur1->next;
//             }
//             else if(cur1Val > cur2Val && cur2){ //cur1->val > cur2->val
//                 mergeNode->next = cur2;
//                 mergeNode = mergeNode->next;
//                 cur2 = cur2->next;
//             }

//         }
//         ListNode* ret = dummyNode->next;
//         delete dummyNode;

//         return ret;
//     }
// };

// //官方代码
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode* preHead = new ListNode(-1);

//         ListNode* prev = preHead;
//         while (l1 != nullptr && l2 != nullptr) {
//             if (l1->val < l2->val) {
//                 prev->next = l1;
//                 l1 = l1->next;
//             } else {
//                 prev->next = l2;
//                 l2 = l2->next;
//             }
//             prev = prev->next;
//         }

//         // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
//         prev->next = l1 == nullptr ? l2 : l1;

//         return preHead->next;
//     }
// };
//模仿官方
class Solution {
public:
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