class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || left==right) return head;

        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        ListNode* prev= dummy;

        for(int i=0;i<left-1;i++){
            prev=prev->next;
        }

        ListNode* curr=prev->next;

        for(int i=0;i<right-left;i++){
            ListNode* temp=curr->next;
            curr->next=temp->next;
            temp->next=prev->next;
            prev->next=temp;
        }
        return dummy->next;
    }
};