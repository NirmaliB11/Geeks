/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  void dfs(Node* root, int s, int d, pair<int,int>&ans)
  {
      s+=root->data;
      d++;
      if(root->left==NULL && root->right==NULL)
      {
         if(d>ans.first)
         {
             ans.first=d;
             ans.second=s;
         }
         if(d==ans.first)
         {
             if(ans.second<s)
             {
                 ans.second=s;
             }
         }
         return;
      }
      if(root->left!=NULL)
      {
          dfs(root->left,s,d,ans);
      }
      if(root->right)
      {
          dfs(root->right,s,d,ans);
      }
  }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        pair<int,int>ans;
        ans={0,0};
        int s=0;
        int d=0;
        dfs(root,s,d,ans);
        return ans.second;
    }
};