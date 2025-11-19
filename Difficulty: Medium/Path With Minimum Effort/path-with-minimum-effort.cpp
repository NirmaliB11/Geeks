class Solution {
  public:
    int minCostPath(vector<vector<int>>& heights) {
        // code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e8));
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int wt  = pq.top().first;
            if(row==n-1&&col==m-1) return wt;
            pq.pop();
            for(int i = 0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m){
                    int newWt = max(abs(heights[nrow][ncol]-heights[row][col]),wt);
                    if(newWt<dist[nrow][ncol]){
                        dist[nrow][ncol] = newWt;
                        pq.push({newWt,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};