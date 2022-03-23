#pragma once

#include<iostream>


using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//arr�������飬n���鳤��
ListNode* createLinkedList(int arr[], int n) {
    //����һ�����飬����һ��������������ͷ
    if (n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);

    ListNode* CurNode = head;
    for (int i = 1; i < n; i++) {
        CurNode->next = new ListNode(arr[i]);
        CurNode = CurNode->next;
    }
    return head;
}

void printLinkedList(ListNode* head) {
    //����һ������ͷ����ӡ����
    ListNode* curNode = head;
    while (curNode != NULL) {
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }
    cout << "NULL" << endl;
    return;
}

void deletLinkedList(ListNode* head) {
    //����һ������ͷ���ͷ��������пռ�
    ListNode* curNode = head;
    while (curNode != NULL) {
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
    return;
}