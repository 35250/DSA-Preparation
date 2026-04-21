Problem: House Robber II (LC: 213)
Link: https://leetcode.com/problems/house-robber-ii/description/
Pattern: Take/Skip Pattern
Approach: Tabulation
  - Since circular array, divide it into two linear arrays and solve
  - Array1: 0th index -> (n-2)th index         Array2: 1st index -> (n-1)th index
  - State: dp[i]= max money that can be robbed from i to n-1
  - Recurrence: dp[i]= max(nums[i] + f(i+2), f(i+1))
  - Return max(array1, array2)
Complexity:
  - Time: O(n)
  - Space: O(1)

Solution: 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n == 1) return nums[0];
        
        int next1= 0, next2= 0;
        for(int i=n-2; i>=0; i--){
            int cur= max(nums[i]+next2, next1);
            next2= next1;
            next1= cur;
        }

        int ans1= next1;
        
        next1= 0, next2= 0;
        for(int i=n-1; i>=1; i--){
            int cur= max(nums[i]+next2, next1);
            next2= next1;
            next1= cur;
        }

        return max(ans1, next1);
    }
};
