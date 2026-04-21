Porblem: Russian Doll Envelopes (LC: 354)
Link: https://leetcode.com/problems/russian-doll-envelopes/
Pattern: Sorting + LIS
Approach:
  - Sort widths in ascending
  - Same width, heights descending
  - Extract heights and find LIS on it
  - Implement Greedy + Binary Search approach
  - Initialize a temp array, for each height, find first >= element, if found replace, if not, append
  - Return the size of the temp array 
Complexity: 
  - Time: O(nlogn)
  - Space: O(n)

Solution:
class Solution {
public: 
    int LIS(vector<int>& nums){
        vector<int> temp;

        for(int i: nums){
            auto it= lower_bound(temp.begin(), temp.end(), i);

            if(it == temp.end()){
                temp.push_back(i);
            }else{
                *it= i;
            }
        }

        return temp.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n= envelopes.size();

        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> nums;
        for(auto& e: envelopes){
            nums.push_back(e[1]);
        }
       
        return LIS(nums);
    }
};
  
