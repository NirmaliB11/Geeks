//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
         int n=x.size();
        stack<char>st;
        if(x[0]==')' || (x[0]=='}' || x[0]==']')) return false;
        for(int i=0;i<n;i++){
            char ch=x[i];
            if(ch=='(') st.push(ch);
            else if(ch=='{') st.push(ch);
            else if(ch=='[') st.push(ch);
            else if(ch==')'){
                if(st.size()>0) {
                    if(st.top()=='(') st.pop();
                    else return false;
                }
                
            }else if(ch=='}'){
                if(st.size()>0) {
                    if(st.top()=='{') st.pop();
                    else return false;
                }
                
            }else if(ch==']'){
                if(st.size()>0){
                    if(st.top()=='[') st.pop(); 
                    else return false;
                }
            }
        }
        return st.empty()==true?true:false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends