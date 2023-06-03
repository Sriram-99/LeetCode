//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    static bool comp(pair<int,int>a,pair<int,int>b){
        return a.first<b.first;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>vvi;
        for(int i=0;i<n;i++){
            vvi.push_back(make_pair(end[i],start[i]));
        }
        sort(vvi.begin(),vvi.end(),comp);
        int last=vvi[0].first;
        int jobs=1;
        for(int i=1;i<n;i++){
            if(vvi[i].second>last){
                jobs++;
                last=vvi[i].first;
            }
        }
        return jobs;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends