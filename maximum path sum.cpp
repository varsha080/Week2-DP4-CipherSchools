class Solution {
public:
int maxi = INT_MIN;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        maxi = max(maxi , root->val+l+r);
        int sum = root->val + max(l , r);
        if(sum<0){
            sum=0;
        }
        return sum;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxi;
    }
};