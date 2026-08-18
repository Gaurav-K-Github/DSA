class Solution {
public:
    void dfs(int node,int parent,map<int,vector<int>>&adj,int &d,vector<int>&vec){
         int val=1;
         for(auto x:adj[node]){
            if(x!=parent){
                dfs(x,node,adj,d,vec);
                val+=vec[x];
                d+=vec[x];
            }
         }
         vec[node]=val;
         return ;
    }
    void dfs1(int node,int parent,map<int,vector<int>>&adj,int d,vector<int>&vec,vector<int>&ans){
         ans[node]=d;
         int n=vec.size();
         for(auto x:adj[node]){
            if(x!=parent){
                dfs1(x,node,adj,d+n-2*vec[x],vec,ans);
            }
         }
         return ;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
          map<int,vector<int>>adj;
          for(auto x:edges){
             adj[x[0]].push_back(x[1]);
             adj[x[1]].push_back(x[0]);
          }
          int d=0;
          vector<int>vec(n,0);
          dfs(0,-1,adj,d,vec); 
          vector<int>ans(n,0);
          ans[0]=d;
          dfs1(0,-1,adj,d,vec,ans);
          return ans;
    }
};