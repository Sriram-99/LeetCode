//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    Node* insertattail(Node*head,Node*one){
        if(!head) return one;
        Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=one;
        return head;
    }
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        int cnt=0;
        int len=0;
        Node*curr=head;
        Node*newhead;
        while(curr){
            len++;
            cnt++;
            if(len==k){
                newhead=curr->next;
                curr->next=NULL;
                return insertattail(newhead,head);
            }
            curr=curr->next;
        }
        
        if(k>cnt){
            k=k%cnt;
        }
        return rotate(head,k);
        
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends