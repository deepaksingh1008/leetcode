class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         set<int> st;
        int i=0;
        int j=0;
        int n = nums.size();
        if(k==0)
             return false;
        while(j<n){
            if(st.find(nums[j])!=st.end()){
                    return true;
            }
             if(abs(i-j)>=k){
                st.erase(nums[i]);
                i++;
                
                
            }
           st.insert(nums[j++]);
        }
        return false;
    }
};