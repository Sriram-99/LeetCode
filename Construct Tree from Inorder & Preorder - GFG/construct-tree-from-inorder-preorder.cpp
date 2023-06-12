//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int search(int in[], int start, int end, int val) {
    if (start > end) return -1;
    if (start == end) return start;
    for (int i = start; i <= end; i++) {
        if (in[i] == val) return i;
    }
    return -1;  // Return -1 if the value is not found
}

    Node*build(int in[],int pre[],int start,int end,int&idx){
        if(start>end) return NULL;
        Node*ans=new Node(pre[idx]);
        
        if(start==end) {
            idx++;
            return ans;
        }
        int val=pre[idx];
        int pos=search(in,start,end,val);
        if(pos==-1) return ans;
        idx++;
        ans->left=build(in,pre,start,pos-1,idx);
        ans->right=build(in,pre,pos+1,end,idx);
        return ans;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int idx=0;
     return build(in,pre,0,n-1,idx);  
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends