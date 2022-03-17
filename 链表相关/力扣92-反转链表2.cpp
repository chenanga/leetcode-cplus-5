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
//                 start = pre; //��ʱ��ָ����Ҫָ��ת���ֵ�ͷ
//                 end = cur;  //��ʱ��ָ����Ҫָ��ת����֮��ĵط�
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
//                     head = cur; //��ʱ�Ǵ�ͷ��ת��������Ҫ�޸�headָ����ȷλ��

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

//�ٷ����볢�Ը���
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL) return NULL;

        // ��Ϊͷ�ڵ��п��ܷ����仯��ʹ������ͷ�ڵ���Ա��⸴�ӵķ�������
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode* pre = dummyNode;
        ListNode* cur = head;
        ListNode* succ = cur->next; //��̽ڵ�

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

// //�ٷ�����
// class Solution {
// public:
//     ListNode *reverseBetween(ListNode *head, int left, int right) {
//         // ���� dummyNode ����һ�������һ������
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