//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

// } Driver Code Ends
//User function Template for C++

/* Linked List node structure
    
struct Node {
	int data;
	struct Node *next;
};

*/

class Solution
{
    public:
    Node* removeAllDuplicates(struct Node* head)
    {
        if(!head || !head->next)return head;
        Node*curr=head;
        Node*prev=NULL;
        Node*newhead=NULL;
        while(curr && curr->next){
            if(curr->data==curr->next->data){
                    int val=curr->data;
                    while(curr && curr->data==val){
                        Node*temp=curr;
                        curr=curr->next;
                        temp->next=NULL;
                        delete temp;
                    }
                  continue;
                
                
            }
            else{
                if(prev==NULL){
                    prev=curr;
                    newhead=curr;
                    curr=curr->next;
                }
                else{
                    prev->next=curr;
                    prev=prev->next;
                    curr=curr->next;
                }
            }
            
        }
        if(!curr){
        prev->next=NULL;
        }
        if(!curr && !prev) return NULL;
        
        if(curr && !prev){
            return curr;
        }
        if(curr && prev){
            prev->next=curr;
        }
                return newhead;
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;


	while (T--)
	{
		int N;

		cin >> N ;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		Solution ob;
		head = ob.removeAllDuplicates(head);
		printList(head);

		cout << "\n";


	}
	return 0;
}

// } Driver Code Ends