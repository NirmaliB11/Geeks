//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        // code here
        int open=0;
        int close=0;
        int maxi=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='(') open++;
            else close++;
            if(open==close){
                maxi=max(maxi,2*open);
            }else if(close>open){
                close=0;
                open=0;
            }
        }
        open=0;
        close=0;
        for(int i=str.size()-1;i>=0;i--){
            if(str[i]=='(') open++;
            else close++;
            if(open==close){
                maxi=max(maxi,2*open);
            }else if(close<open){
                close=0;
                open=0;
            }
        }
        return maxi;
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
    }
    return 0;
}
// } Driver Code Ends