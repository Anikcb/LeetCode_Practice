class Solution {
public:
    int arr[3]={1, 7, 30};
    int dp[370];
    int fun(vector<int>& days, vector<int>& costs,int n, int p){
        if(p>=n)return 0;
        int x=1e8;
        if(dp[p]!=-1)return dp[p];
        for(int j=0;j<3;j++)
        {
            int lb=lower_bound(days.begin(), days.end(),days[p]+arr[j])-days.begin();
            x=min(fun(days, costs, n, lb)+costs[j],x);
        }
        return dp[p]=x;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
         int n=days.size();
         memset(dp,-1,sizeof(dp));
         return fun(days, costs, n, 0);
    }

};
