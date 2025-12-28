class Solution {
  public:
    int minTime(vector<int>& ranks, int n) {

         long long l = 0, r = 0;
        
        for (int rank : ranks) {
            r = max(r, 1LL * rank * n * (n + 1) / 2);
        }
        
        while (l < r) {
            long long mid = l + (r - l) / 2;
            long long total = 0;
            
            for (int rank : ranks) {
                long long cnt = 0, time = 0;
                long long k = 1;
                while (time + k * rank <= mid) {
                    time += k * rank;
                    cnt++;
                    k++;
                }
                total += cnt;
                if (total >= n) break;
            }
            
            if (total >= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};