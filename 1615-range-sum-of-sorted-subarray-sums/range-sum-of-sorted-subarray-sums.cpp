class Solution {
public:
    vector<int> findSubArray(vector<int>& nums, int n){
        vector<int> ans;
        for(int i=0;i<n;i++){
             ans.push_back(nums[i]);
            int sum = nums[i];
            for(int j=i+1;j<n;j++){
                sum+=nums[j];
                ans.push_back(sum);
            }
        }
        return ans;
    }
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        if(n==1){
            return nums[0];
        }
        
        int MOD = 1000000007;
         vector<int> result = findSubArray(nums,n);
         sort(result.begin(),result.end());
         int ans=0;
         for(int i = left-1;i<right;i++){
             ans = (ans%MOD + result[i]%MOD)%MOD;
         }
        return ans;
    }
};