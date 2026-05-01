Problem: Number of Longest Increasing Subsequence (LC: 673)
Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
Paattern: Sequence Extension via DP
Approach:
  - State: length[i]= LIS ending at i
           count[i]= number of LIS ending at i
  - Constraint: nums[i] > nums[j]
  - Recurrence: length[i]= length[j]+1 count[i]= count[j] OR count[i]+=count[j]
  - Simulating sequence extension if constraint satisfies and incrementing count
  - Find max LIS length and sum up the count of that length
Complexity:
  - Time: O(n^2)
  - Space: O(n)

Solution:
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> length(n, 1);
        vector<int> count(n, 1);
        int maxLen= 0;

        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i] > nums[j]){
                    if(length[j]+1 > length[i]){
                        length[i]= length[j] + 1;
                        count[i]= count[j];
                    
                    }else if(length[j]+1 == length[i]){
                        count[i]+= count[j];
                    
                    }
                }
            }

            maxLen= max(maxLen, length[i]);
        }

        int sum= 0;
        for(int i=0; i<n; i++){
            if(length[i] == maxLen){
                sum+= count[i];
            }
        }

        return sum;
    }
};
