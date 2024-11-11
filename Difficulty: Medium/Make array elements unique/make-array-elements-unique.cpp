//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        long long ans =0;
        set<long long> st;
        
        for(long long a : arr) {
            auto pos = st.find(a);
            if(st.find(a)!=st.end()) {
                long long val = *st.rbegin()+1;
                ans+=(val-a);
                a=val;
            }
            st.insert(a);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends