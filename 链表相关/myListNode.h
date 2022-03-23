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

//arr传入数组，n数组长度
ListNode* createLinkedList(int arr[], int n) {
    //给定一个数组，创建一个链表，返回链表头
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
    //给定一个链表头，打印所有
    ListNode* curNode = head;
    while (curNode != NULL) {
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }
    cout << "NULL" << endl;
    return;
}

void deletLinkedList(ListNode* head) {
    //给定一个链表头，释放链表所有空间
    ListNode* curNode = head;
    while (curNode != NULL) {
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
    return;
}