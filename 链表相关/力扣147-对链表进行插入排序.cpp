#include<iostream>
#include"myListNode.h"
#include<vector>



using namespace std;


////vector容器办法，耗时长
// class Solution {
// public:
//     ListNode* insertionSortList(ListNode* head) {

//         //sort 0 1 2
//         ListNode* dummyNode = new ListNode(-50001);
//         dummyNode->next = head;
//         ListNode* cur = dummyNode;
//         vector<ListNode*> vec;
//         while(cur != NULL){
//             vec.push_back(cur);
//             cur = cur->next;
//         }
//         for(int i = 2; i < vec.size() ;i ++ ){ //0 dummyNode  1 head 2开始排序

//             int j = i;
//             while(j >= 1 && vec[j]->val < vec[j-1]->val){

//                 //和上一个交换
//                 vec[j-2]->next = vec[j];
//                 vec[j-1]->next = vec[j]->next;
//                 vec[j]->next = vec[j-1];
//                 swap(vec[j],vec[j-1]);
//                 j--;
//             }


//         }
//         ListNode* ret = dummyNode->next;
//         return ret;

//     }

// };

//不借助vector
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return NULL;
        //sort 0 1 2
        ListNode* dummyNode = new ListNode(-50001);
        dummyNode->next = head;
        ListNode* start = head;
        ListNode* end = head; // [strat,end]排序
        ListNode* cur = head->next; //待排序节点
        while (cur != NULL) {
            if (cur->val >= end->val) {
                end = cur;
                cur = cur->next;
            }
            else { // 从头遍历
                ListNode* mycur = cur;
                cur = cur->next;
                if (start->val > mycur->val) {
                    end->next = cur;
                    dummyNode->next = mycur;
                    mycur->next = start;
                    start = dummyNode->next;
                }
                else {
                    ListNode* pre = start;
                    ListNode* prePre = dummyNode; //pre的pre
                    while (pre->val < mycur->val) {
                        //往后遍历
                        prePre = pre;
                        pre = pre->next;
                    }
                    //此时应插入prepre,pre之间
                    end->next = cur;
                    prePre->next = mycur;
                    mycur->next = pre;
                }
            }
        }

        ListNode* ret = dummyNode->next;
        return ret;
    }
};

int main() {
    int arr[] = { 4,2,1,3 };
    int n = sizeof(arr) / sizeof(int);

    ListNode* head = createLinkedList(arr, n);
    printLinkedList(head);

    ListNode* head2 = Solution().insertionSortList(head);
    printLinkedList(head2);

	system("pause");
	return 0;
}