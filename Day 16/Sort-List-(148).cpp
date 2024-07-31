/**
#incklude<bits/std.c++.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 #include<bits/stdc++.h>
class Solution {
public:
    ListNode *findMiddle(ListNode* head){
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode *mergeSort(ListNode *list1, ListNode *list2){
        ListNode*dummyNode= new ListNode(-1);
        ListNode *temp=dummyNode;
        while(list1!=NULL && list2!=NULL){
            if(list1->val <list2->val){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list2) temp->next=list2;
        else temp->next=list1;
        return dummyNode->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *middle=findMiddle(head);
        ListNode *leftHead=head;
        ListNode *rightHead=middle->next;
        middle->next=NULL;
        leftHead=sortList(leftHead);
        rightHead=sortList(rightHead);
        return mergeSort(leftHead, rightHead);
    }
};