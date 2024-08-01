class Solution {
public:
   ListNode *reverseLinkedLists(ListNode *head){
        ListNode *temp=head;
        ListNode *prev= NULL;
        while(temp!=NULL){
            ListNode *front= temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
   }
   ListNode* generateKthNode(ListNode* temp, int k){
       k-=1;
       while(temp!=NULL && k>0){
           k--;
           temp=temp->next;
       }
       return temp;
   }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevLast=NULL;
        while(temp!=NULL){
            ListNode *kthNode=generateKthNode(temp,k);
            if(kthNode==NULL){
                if(prevLast) prevLast->next=temp;
                break;
            }
            ListNode* nextNode=kthNode->next;
            kthNode->next= NULL;
            reverseLinkedLists(temp);
            if(temp== head) head=kthNode;
            else prevLast->next=kthNode;
            prevLast=temp;
            temp=nextNode;
        }
        return head;
    }
};