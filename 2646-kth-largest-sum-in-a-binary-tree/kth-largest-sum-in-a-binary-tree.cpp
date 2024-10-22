/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == NULL){
            return -1;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        //int level = 0;
        long long sum=0;
        vector<long long> ans;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            if(front==NULL){
              //  level++;
                ans.push_back(sum);
                sum=0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                sum+=front->val;
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
        }
        
        if(ans.size()<k){
            return -1;
        }
        
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        
        return ans[k-1];
        
    }
};