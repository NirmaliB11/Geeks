//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int mod=1e9+7;
    long long int fun(int n,vector<long long int> &dp)
    {
        if(n==0||n==1){
            return (long long int)n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=(fun(n-1,dp)%mod+fun(n-2,dp)%mod)%mod;
    }
    long long int topDown(int n) {
        // code here
        vector<long long int> dp(n+1,-1);
        return fun(n,dp);
    }
    long long int bottomUp(int n) {
        // code here
        vector<long long int> dp(n+1,0);
        dp[0]=0ll,dp[1]=1ll;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
        }
        return dp[n]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends