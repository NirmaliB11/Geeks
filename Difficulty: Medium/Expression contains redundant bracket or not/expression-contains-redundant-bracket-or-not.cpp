class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char> st;
        for(auto i:s){
            if(i!=')')st.push(i);
            else{
                int c=0;
                while(!st.empty()&&st.top()!='('){
                    st.pop();
                    c++;
                }
                if(st.empty()||c<3)return true;
                st.pop();
                st.push('x');
            }
        }
        return false;
    }
};