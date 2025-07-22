class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int n=arr.size();
        unordered_set<int> u;
        for(int i:arr)
        {
            if(i>0)
            u.insert(i);
        }
        for(int i=1;i<=n;i++)
        {
            if(u.find(i)==u.end())
            return i;
        }
        return n+1;
    }
};