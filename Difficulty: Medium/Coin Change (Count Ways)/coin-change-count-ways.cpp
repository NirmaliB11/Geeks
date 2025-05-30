//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int f(int ind, int sum, vector<int> &coins, vector<vector<int>> &dp){
        if(sum == 0) return 1;
        if(ind < 0) return 0;

        if(dp[ind][sum] != -1) return dp[ind][sum];

        int ways = 0;
        for(int coin_sum=0; coin_sum <= sum; coin_sum += coins[ind]){
            ways += f(ind-1, sum - coin_sum, coins, dp);
        }
        return dp[ind][sum] = ways;
    }
    int count(vector<int>& coins, int sum) {
        vector<vector<int>> dp(coins.size(), vector<int>(sum+9, -1));
        return f(coins.size()-1, sum, coins, dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends