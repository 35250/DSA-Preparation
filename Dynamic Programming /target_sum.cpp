Problem: Target Sum (LC: 494)
Link: https://leetcode.com/problems/target-sum/description/
Pattern: Knapsack
Approach:
  - Reduce the problem to knapsack
  - P-> sum of elements which "+" before them     N-> sum of elements which has "-" before them
  - P+N= totalSum   P-N= target   Combining both equations, we get P= (total+target)/2
  - Now problem becomes find number of subsets which has a sum equal to P
  - Edge Cases: if((total+target)%2 != 0) return 0;    if(abs(target) > total) return 0;
  - Base Case: dp[0]= 0;
  - State: dp[i][j]= total number of subsets from i to n-1 with a sum j
  - Recurrence: dp[i][j]= dp[i+1][j-nums[i]] + dp[i+1][j]
Complexity:
  - Time: O(n*sum)
  - Space: O(sum)

Solution:
class Solution {
public:
    int n;
    vector<int> dp;

    int tabulate(vector<int>& nums, int target){
        for(int i=n-1; i>=0; i--){
            for(int j=target; j>=nums[i]; j--){
                dp[j]= dp[j-nums[i]] + dp[j];  
            }
        }

        return dp[target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n= nums.size();

        int total= 0;
        for(int i: nums) total+= i;

        if((total + target)%2 != 0) return 0;
        if(abs(target) > total) return 0;

        int sum= (total+target)/2;
        dp.assign(sum+1, 0);
        dp[0]= 1;

        return tabulate(nums, sum);
    }
};
  
  
