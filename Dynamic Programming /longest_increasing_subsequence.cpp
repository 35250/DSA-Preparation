Problem: Longest Increasing Subsequence (LC: 300)
Link: https://leetcode.com/problems/longest-increasing-subsequence/description/
Pattern: LIS
Approach 1: DP
  - State -> dp[i][j]: longest subsequence length from i to n-1 elements such that previous element is j
  - Recurrence -> dp[i][j]= max(1 + dp[i+1][i], dp[i+1][j])
  - Consider elements if constraint satisfies (no previous element || nums[i] > nums[j])

Approach 2: Greedy + Binary Search
  - temp[k]: maintain the smallest possible tail of subsequence of length k + 1
  - for each element:
    - find the first >= element
    - if found replace it, if not append it
  - longest subsequence length: size of temp array

Complexity: 
  - Time: DP-> O(n^2)   Binary Search-> O(nlogn)
  - Space: DP-> O(n^2)  Binary Search-> O(n)

Solution:
class Solution {
public:
    int binarySearch(vector<int>& temp, int x){
        int st= 0, end= temp.size()-1, ans= -1;

        while(st <= end){
            int mid= st+(end-st)/2;

            if(temp[mid] > x){
                ans= mid;
                end= mid-1;
                
            }else if(temp[mid] < x){
                st= mid+1;
            
            }else{
                ans= mid;
                break;
            }
        }

        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;

        for(int i: nums){
            int idx= binarySearch(temp, i);

            if(idx == -1){
                temp.push_back(i);
            }else{
                temp[idx]= i;
            }
        }

        return temp.size();
    }
};
