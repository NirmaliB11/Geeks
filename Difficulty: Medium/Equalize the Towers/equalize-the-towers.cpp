class Solution {
  public:
    int helper(vector<int>& heights, vector<int>&cost,int h,int n)
    {
        int c = 0;
        for(int i = 0;i<n;i++)
        {
            c = c + abs(heights[i] - h) * cost[i];
        }
        return c;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int n = cost.size();
        int l = *min_element(heights.begin(), heights.end());
        int r = *max_element(heights.begin(), heights.end());
        int min_cost = INT_MAX;
        bool flag = true;
        
        while(l<=r && flag)
        {
            int mid = (l+r)/2;
            int c = helper(heights,cost,mid,n);
            int hh = helper(heights,cost,mid+1,n);
            int gg = helper(heights,cost,mid-1,n);
            if(gg>=c && hh>=c)
            {
                min_cost = c;
                flag = false;
                break;
            }
            else if( hh>=c && gg<c)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
            
        }
        return min_cost;
    }
};