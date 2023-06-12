//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/
int search(int inorder[],int val,int start,int end){
    for(int i=start;i<=end;i++){
        if(inorder[i]==val) return i;
    }
    return -1;
     
}
int* extract(int inorder[], int level[], int start, int end, int n) {
    map<int, int> vvi;
    for (int i = start; i <= end; i++) {
        vvi[inorder[i]]++;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (vvi[level[i]] > 0) {
            count++;
        }
    }

    int* newLevel = new int[count];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (vvi[level[i]] > 0) {
            newLevel[j++] = level[i];
            vvi[level[i]]--;
        }
    }

    return newLevel;
}


Node* buildTree(int inorder[], int levelOrder[], int start, int end,int n)
{
   if(start>end)return NULL;
   Node*curr=new Node(levelOrder[0]);
   if(start==end) return curr;
   int val=levelOrder[0];
   int pos=search(inorder,val,start,end);
   if(pos==-1) return curr;
   int *left=extract(inorder,levelOrder,start,pos-1,n);
   int *right=extract(inorder,levelOrder,pos+1,end,n);
   
   curr->left=buildTree(inorder,left,start,pos-1,n);
   curr->right=buildTree(inorder,right,pos+1,end,n);
  return curr;

}