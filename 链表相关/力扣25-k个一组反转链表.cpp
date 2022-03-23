#include<iostream>
#include"myListNode.h"

using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* cur = head;
        ListNode* start = dummyNode;
        
        while (cur) {
            ListNode* end = start;
            for (int i = 0; i < k; i++) {
                end = end->next;
                if (!end) {
                    ListNode* ret = dummyNode->next;
                    delete dummyNode;
                    return ret;
                }

            }
           
            ListNode* succ = end->next;//记录当前反转区间的下一个节点
            pair<ListNode*, ListNode*> resNode = __reverseKGroup(cur, end); //反转cur  到 end的链表
            start->next = resNode.first;
            resNode.second->next = succ;
            start = resNode.second;
            cur = resNode.second->next;


        }

        ListNode* ret = dummyNode->next;
        delete dummyNode;
        return ret;
    }
private:
    pair<ListNode*, ListNode*> __reverseKGroup(ListNode* head, ListNode* end) {
        //反转head 到end的,返回反转后的头和尾
        ListNode* pre = end->next;
        ListNode* cur = head;
        while (pre != end) {
            ListNode* succ = cur->next;
            cur->next = pre;
            pre = cur;
            cur = succ;
        }

        return { pre, head };
    }
};

int main() {

    int arr[] = { 1,2,3,4,5,6,7,8,9 };
    ListNode* shuru = createLinkedList(arr, sizeof(arr) / sizeof(int));
    printLinkedList(Solution().reverseKGroup(shuru, 2));

	system("pause");
	return 0;
}