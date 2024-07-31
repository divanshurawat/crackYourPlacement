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
    ListNode* partition(ListNode* head, int x) {
        ListNode *small= new ListNode(-1);
        ListNode *large= new ListNode(-1);
        ListNode *smallPointer = small;
        ListNode *largePointer = large;
        ListNode *temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                smallPointer->next=temp;
                smallPointer=smallPointer->next;
            }
            else{
                largePointer->next=temp;
                largePointer=largePointer->next;
            }
            temp=temp->next;
        }
        largePointer->next=NULL;
        smallPointer->next=large->next;
        ListNode*result= small->next;

        delete small;
        delete large;
        
        return result;
    }
};