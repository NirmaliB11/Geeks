//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        int n=intervals.size();
        if(newInterval[1]<intervals[0][0]){
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        else if(newInterval[0]>intervals[n-1][1]){
            intervals.push_back(newInterval);
            return intervals;
        }
        else
        {
            for(int i=0;i<n;i++){
                if(newInterval[0]<=intervals[i][0])
                {
                    intervals.insert(intervals.begin()+i,newInterval);
                    break;
                }
            }
            if(n==intervals.size()) intervals.push_back(newInterval);
            int i=1; 
            while(i<intervals.size())
            {
                if(intervals[i][0]>intervals[i-1][1]) i++;
                else
                {
                    intervals[i-1][1]=max(intervals[i-1][1],intervals[i][1]);
                    intervals.erase(intervals.begin()+i);
                }
            }
        }
        return intervals;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends