class Solution {
public:
    bool twoPart(int *arr, int n)
{
    int totalSum = 0, i;
    for(i=0; i<n; i++)totalSum += arr[i];
    if( (totalSum & 1) != 0)return false;
    int partSum = totalSum/2;
    bool partArr[partSum+1][n+1];
    for (i = 0; i <= n; i++)partArr[0][i] = true;
    for (i = 1; i <= partSum; i++)partArr[i][0] = false;
    for (i = 1; i <= partSum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            partArr[i][j] = partArr[i][j-1];
            if (i >= arr[j-1])
                partArr[i][j] = partArr[i][j] || partArr[i - arr[j-1]][j-1];
        }
    }
    return partArr[partSum][n];
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int arr[n+2];
        for(int i=0;i<n;i++)arr[i]=nums[i];
        return twoPart(arr,n);
    }
};
