Problem: MinCost Climbing Stairs (LC: 746)
Link: https://leetcode.com/problems/min-cost-climbing-stairs/description/
Pattern: Optimizing DP
Approach: Tabulation
  - State: dp[i]-> min cost to reach top from i
  - Recurrence: dp[i]= cost[i] + min(f(i+1), f(i+2))
  - Base case: int next1= 0, next2= 0;
Complexity:
  - Time: O(n)
  - Space: O(1)

Solution:
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        
        int next1=0, next2= 0;

        for(int i=n-1; i>=0; i--){
            int cur= cost[i] + min(next1, next2);
            next2= next1;
            next1= cur;
        }

        return min(next1, next2);
    }
};
