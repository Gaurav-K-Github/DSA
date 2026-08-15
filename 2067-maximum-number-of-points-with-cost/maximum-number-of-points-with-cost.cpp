class Solution {
private:
   long long solve(int i,int j,int n,int m,vector<vector<int>>& points,
             vector<vector<int>> &dp){
    if(i==n){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    long long maxSum=0;

    for(int k=0;k<m;k++){
        long long sum=points[i][k] -abs(k-j) + solve(i+1,k,n,m,points,dp);
        maxSum=max(maxSum,sum);
    }

    return dp[i][j]=maxSum;

   }    
public:
    long long maxPoints(vector<vector<int>>& points) {
        //1.Memoization
        // int n=points.size();
        // int m=points[0].size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // long long maxSum=INT_MIN;
        
        // for(int i=0;i<m;i++){
        //     long long sum=solve(0,i,n,m,points,dp);
        //     maxSum=max(maxSum,sum);
        // }
        
        // return maxSum;

        //2.Tabulation
        // int n=points.size();
        // int m=points[0].size();
        
        // vector<long long> next(m, 0);
        // vector<long long> curr(m, 0);
 
        // for(int i=n-1;i>=0;i--){
        //     for(int j=0;j<m;j++){
        //         long long maxSum=0;
        //         for(int k=0;k<m;k++){
        //             long long sum=points[i][k] -abs(k-j) + next[k];
        //              maxSum=max(maxSum,sum);
        //         }
        //         curr[j]=maxSum;
        //     }
        //     next=curr;
        // }

        // long long maxSum=INT_MIN;
        // for(int j=0;j<m;j++){
        //     long long sum=next[j];
        //     maxSum=max(maxSum,sum);
        // }
        
    
        int n = points.size();
        int m = points[0].size();


        vector<long long> next(m,0);
        vector<long long> curr(m,0);

        for (int i=n-1;i>=0;i--) {
            vector<long long> leftMax(m),rightMax(m);
            leftMax[0]=next[0];

            for (int j=1;j<m;j++) {
                leftMax[j]=max(leftMax[j-1],next[j]+j);
            }

            rightMax[m-1]=next[m-1]-(m-1);

            for (int j=m-2;j>=0;j--) {
                rightMax[j]=max(rightMax[j+1],next[j]-j);
            }

            for (int j=0; j<m;j++) {
                curr[j]=points[i][j] + max(leftMax[j]-j,rightMax[j]+j);
            }
            next=curr;
        }


        long long maxSum=LLONG_MIN;
        for (int j=0;j<m;j++) {
            maxSum=max(maxSum,next[j]);
        }

        return maxSum;
    }
};