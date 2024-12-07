//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to count inversions in the array.
    int cnt=0;
    void merge(vector<int> &arr,int l,int mid,int r)
    {
        vector<int> temp;
        int left=l;
        int right=mid+1;
        while(left<=mid&&right<=r)
        {
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left+=1;
            }
            else{
                cnt+=(mid-left+1);
                temp.push_back(arr[right]);
                right+=1;
            }
        }
        while(left<=mid)
        {
            temp.push_back(arr[left]);
            left+=1;
        }
        while(right<=r)
        {
            temp.push_back(arr[right]);
            right+=1;
        }
        
        for(int i=l;i<=r;i++)
        {
            arr[i]=temp[i-l];
        }
    }
    void mergeSort(vector<int> &arr,int l,int r)
    {
        if(l>=r) return;
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n=arr.size();
        mergeSort(arr,0,n-1);
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends