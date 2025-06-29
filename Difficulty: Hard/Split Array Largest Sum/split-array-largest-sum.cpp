class Solution {
  public:
     bool solve(vector<int>&arr,int k,int mid){
      int sum=0;
      int cnt=1;
      for(int i=0;i<arr.size();i++){
          if(sum+arr[i]<=mid){
              sum+=arr[i];
          }
          else{
              cnt++;
              if(cnt>k||arr[i]>mid){
                  return false;
              }
              sum=arr[i];
          }
      }
      return true;
      
  }
    int splitArray(vector<int>& arr, int k) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        int ans=0;
        int s=0;
        int e=sum;
        int mid=s+e>>1;
        while(s<=e){
            if(solve(arr,k,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+e>>1;
        }
        return ans;
    }
};