//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int len(Node *head){
        int temp=0;
        while(head){
            temp++;
            head=head->next;
        }
        return temp;
    }
    int help(Node *head1,Node *head2){
        if(!head1 and !head2)return 0;
        if(head1->data>head2->data)return 1;
        if(head2->data>head1->data)return 2;
        return help(head1->next,head2->next);
    }
    Node* rev(Node *head){
        Node *curr=head,*prev=NULL,*nxt=NULL;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        Node *ans=new Node(0);
        while(head1 and head1->data==0)head1=head1->next;
        while(head2 and head2->data==0)head2=head2->next;
        if(!head1 and !head2)return ans;
        if(!head1)return head2;
        if(!head2)return head1;
        Node *greater=head1,*less=head2;
        if(len(head2)>len(head1)){
            greater=head2;
            less=head1;
        }
        else if(len(head1)==len(head2)){
            if(help(head1,head2)==2){
                greater=head2;
                less=head1;
            }
            else if(help(head1,head2)==0){
                return ans;
            }
        }
        greater=rev(greater);
        less=rev(less);
        Node *temp=ans;
        while(less){
            if(greater->data>=less->data){
                temp->next=new Node(greater->data-less->data);
            }
            else{
                temp->next = new Node(greater->data+10-less->data);
                Node *nxt = greater->next;
                while(nxt->data==0){
                    nxt->data=9;
                    nxt=nxt->next;
                }
                nxt->data=nxt->data-1;
            }
            greater=greater->next;
            less=less->next;
            temp=temp->next;
        }
        while(greater){
            temp->next=new Node(greater->data);
            temp=temp->next;
            greater=greater->next;
        }
        ans = rev(ans->next);
        while(ans and ans->data==0)ans=ans->next;
        return ans;
    }

};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends