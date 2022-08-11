class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector< vector<int> >v(numRows);
        int dp[numRows+5][numRows+5];
        dp[0][0]=1;dp[0][1]=0;
        v[0].push_back(1);
        for(int i=1;i<numRows;i++)
        {
            for(int j=0;j<=i;j++)
            {
                dp[i][j]=0;
                if(j-1>=0)dp[i][j]+=dp[i-1][j-1];
                dp[i][j]+=dp[i-1][j];
                v[i].push_back(dp[i][j]);
            }
            dp[i][i+1]=0;
        }
        
        return v;
        
    }
};
