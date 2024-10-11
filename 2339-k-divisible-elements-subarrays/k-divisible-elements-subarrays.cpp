class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
           set<vector<int>> st;  // To store distinct subarrays
        for (int i = 0; i < nums.size(); i++) {
            int n = k;  // Number of allowed divisible elements by p
            vector<int> v1;  // Subarray starting from index i
            
            for (int j = i; j < nums.size(); j++) {
                v1.push_back(nums[j]);  // Expand the subarray
                
                // Check if the current element is divisible by p
                if (nums[j] % p == 0) {
                    n--;  // Decrease the count of allowable divisible elements
                }
                
                // If `n` becomes negative, we break out since no valid subarrays can be formed further
                if (n < 0) {
                    break;
                }
                
                // Insert the subarray if it's not already in the set
                st.insert(v1);
            }
        }
        return st.size();
    }
};