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
    ListNode* middleNode(ListNode* head) {
    ListNode *slow=head;
    ListNode *fast= head;
    ListNode *temp=head;
    int cnt=1;
    while(temp->next!=NULL){
        temp=temp->next;
        cnt++;
    }
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(cnt%2==0) return slow->next;
    else return slow;
    }
};