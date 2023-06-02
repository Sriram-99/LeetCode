//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

    class Node{
        public:
        int data;
        Node* left;
        Node* right;
        Node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
    };
    class cmp{
        public:
        bool operator()(Node*a,Node*b){
            return a->data>b->data;
        }
    };
class Solution
{
    
	public:
	    void traverse(vector<string>&vvi,Node*root,string st){
	        if(!root) return;
	        if(!root->left && !root->right) vvi.push_back(st);
	        traverse(vvi,root->left,st+"0");
	        traverse(vvi,root->right,st+"1");
	        return;
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		  priority_queue<Node*,vector<Node*>,cmp>vvi;
		  for(int i=0;i<N;i++){
		      Node*temp=new Node(f[i]);
		      vvi.push(temp);
		  }
		  while(vvi.size()>1){
		      Node*one=vvi.top();
		      vvi.pop();
		      Node*two=vvi.top();
		      vvi.pop();
		      Node*newNode=new Node(one->data+two->data);
		      newNode->left=one;
		      newNode->right=two;
		      vvi.push(newNode);
		  }
		  Node* root= vvi.top();
		  vector<string>ans;
		  traverse(ans,root,"");
		  return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends