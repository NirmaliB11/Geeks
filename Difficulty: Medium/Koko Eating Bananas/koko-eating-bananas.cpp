class Solution {
  public:
  
    bool check(vector<int>& arr, int k, int mid)
    {
        int s=0;
        
        for(int i=0;i<arr.size();i++)
        {
            int rem=arr[i]%mid;
            
            s=s+arr[i]/mid;
            
            if(rem!=0)
            {
                s=s+1;
            }
        }
        
        return s<=k;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low=1;
        int high=*max_element(arr.begin(),arr.end());
        
        int res=0;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(check(arr,k,mid))
            {
                res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return res;
        
    }
};