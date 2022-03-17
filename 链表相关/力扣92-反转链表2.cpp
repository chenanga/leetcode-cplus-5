#include<iostream>


using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// class Solution {
// public:
// 	ListNode* reverseBetween(ListNode* head, int left, int right) {
//         if (head == NULL) return NULL;
//         int index = 1;
//         ListNode* pre = NULL;
//         ListNode* cur = head;
//         ListNode* next = cur->next;
//         ListNode* start = cur;
//         ListNode* end = cur;

//         while (index < right) {
//             if (index >= left) {
//                 start = pre; //此时的指针需要指向反转部分的头
//                 end = cur;  //此时的指针需要指向反转部分之后的地方
//                 pre = NULL;
//                 while (index < right) {
//                     cur->next = pre;
//                     pre = cur;
//                     cur = next;
//                     next = next->next;
//                     index++;
//                 }
//                 if(cur->next != NULL)
//                     end->next = next;

//                 cur->next = pre;
//                 if (start != NULL)
//                     start->next = cur;
//                 else
//                     head = cur; //此时是从头反转，所有需要修改head指向正确位置

//             }
//             pre = cur;
//             cur = next;
//             if(next!=NULL)
//                 next = next->next;

//             index++;
//         }
//         return head;
// 	}
// };

//官方代码尝试复现
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL) return NULL;

        // 因为头节点有可能发生变化，使用虚拟头节点可以避免复杂的分类讨论
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode* pre = dummyNode;
        ListNode* cur = head;
        ListNode* succ = cur->next; //后继节点

        for (int i = 1; i < left; i++) {
            pre = cur;
            cur = cur->next;
            succ = cur->next;
        }

        for (int i = 0; i < right - left; i++) {
            cur->next = succ->next;
            succ->next = pre->next;
            pre->next = succ;
            succ = cur->next;
        }


        return dummyNode->next;
    }
};

// //官方代码
// class Solution {
// public:
//     ListNode *reverseBetween(ListNode *head, int left, int right) {
//         // 设置 dummyNode 是这一类问题的一般做法
//         ListNode *dummyNode = new ListNode(-1);
//         dummyNode->next = head;
//         ListNode *pre = dummyNode;
//         for (int i = 0; i < left - 1; i++) {
//             pre = pre->next;
//         }
//         ListNode *cur = pre->next;
//         ListNode *next;
//         for (int i = 0; i < right - left; i++) {
//             next = cur->next;
//             cur->next = next->next;
//             next->next = pre->next;
//             pre->next = next;
//         }
//         return dummyNode->next;
//     }
// };
int main() {

	system("pause");
	return 0;
}