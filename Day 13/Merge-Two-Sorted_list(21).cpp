/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*newNode= new ListNode(-1);
        ListNode* dummyHead=newNode;
        ListNode* curr1=list1;
        ListNode* curr2=list2;
        while(curr1!=NULL && curr2!=NULL){
            if(curr1->val<=curr2->val){
                newNode->next=curr1;
                newNode=newNode->next;
                curr1=curr1->next;
            }
            else{
                newNode->next=curr2;
                newNode=newNode->next;
                curr2=curr2->next;
            }
        } 
        if(curr1!=NULL){
            while(curr1!=NULL){
                newNode->next=curr1;
                newNode=newNode->next;
                curr1=curr1->next;
            }
        }
        if(curr2!=NULL){
            while(curr2!=NULL){
                newNode->next=curr2;
                newNode=newNode->next;
                curr2=curr2->next;
            }
        }
        return dummyHead->next;
    }
};