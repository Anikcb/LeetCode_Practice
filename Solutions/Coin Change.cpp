class Solution {
public:
typedef long long ll;
ll dp[10005][15];

int fun(vector<int>& coins, int w, int n, ll sum, int pos)
{
    if(sum==w)return 0;
    if(sum>w || pos>=n)return 1e9;

    int x=1e9;
    if(dp[sum][pos]!=-1)return dp[sum][pos];

    x=min(fun(coins, w, n, sum+coins[pos], pos)+1, x);
    x=min(fun(coins, w, n, sum, pos+1),x);
    return dp[sum][pos]=x;
}

int coinChange(vector<int>& coins, int amount) {
    memset(dp, -1, sizeof(dp));
    int val = fun(coins, amount, coins.size(), 0, 0);
    if(val==1e9)return -1;
    else return val;
}

};
