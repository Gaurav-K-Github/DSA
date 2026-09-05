class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        //for every one i can look at prev and up and diagonally top left
        //if all of those are one than it can the one which we are adding can form a square of size 1 and side 2. thus count+=2;
        //similarly if minimum of all those three is added to the count;
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;
        for(int i = 0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int top = 0;
                int left = 0;
                int topleft = 0;
                if(i!=0) left = matrix[i-1][j];
                if(j!=0) top = matrix[i][j-1];
                if(i!=0 && j!=0) topleft = matrix[i-1][j-1];
                
                if(matrix[i][j] == 1){
                    int temp = min({left,top,topleft});
                    if(temp<=0) count++; //sqaure of side 1 is possible
                    else count+=(temp+1);
                    matrix[i][j] = max(matrix[i][j],temp+1);
                }

            }
        }
        return count;
    }
};