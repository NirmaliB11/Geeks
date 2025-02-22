//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& s) {
        // code here
        int n=s.size();
        stack<pair<int,char>>st;
        map<pair<int,char>,int>hashmap;
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top().second=='(' && s[i]==')'){
                st.pop();
                
                if(st.empty()){
                    ans=max(ans,i+1);
                } else if(!st.empty() && 
                hashmap.find(st.top())!=hashmap.end()){
                    ans=max(ans,i-hashmap[st.top()]);
                }
            } else{
                st.push({i,s[i]});
                hashmap[{i,s[i]}]=i;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends