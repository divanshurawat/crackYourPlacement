bool isPalindrome(ListNode* head) {
        vector<int>v;
        ListNode* temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int i=0, j=v.size()-1;
        while(i<=j){
            if(v[i]!=v[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }