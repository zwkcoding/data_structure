class Solution {
    int dp[1000];
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int ans = INT_MIN;
        if(array.size() == 1) return array[0];  // special case
        dp[0] = array[0];
        for(int i = 1; i < array.size(); i++)  {
            // 找到以该元素结尾的子序列的最大和
            if(dp[i-1] <= 0)  {
                dp[i] = array[i];
            } else  {
                dp[i] = dp[i-1] + array[i];
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    
    }
};
