//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  #include <bits/stdc++.h> 
int taskScheduler( vector<char> & tasks, int n, int t) {
    priority_queue<int>pq;
    unordered_map<char,int>mp;
    for(int i=0;i<n;i++){
        mp[tasks[i]]++;
    }
    for(auto x:mp){
        pq.push(x.second);
    }
    queue<pair<int,int>>q;
    int time=0;
    while(!pq.empty() || !q.empty() ){
        time++;
        if(!q.empty() && q.front().second==time){
            int val=q.front().first;
            pq.push(val);
            q.pop();
        }
        if(!pq.empty()){
            int val=pq.top();
            pq.pop();
            int tm=time+t+1;
           if(val-1>0){
               q.push({val-1,tm});
           }
        }
    }
    return time;
}
    int leastInterval(int N, int K, vector<char> &tasks) {
       return taskScheduler(tasks,N,K);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends