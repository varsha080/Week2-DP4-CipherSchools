class Solution {
public:

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>>m;
    queue<pair<TreeNode*, pair<int, int>>>q;
    q.push({root, {0, 0}});
    while(!q.empty()){
        root=q.front().first;
        int vert=q.front().second.first, lvl=q.front().second.second;
        q.pop();
        m[vert][lvl].insert(root->val);
        if(root->left!=NULL){q.push({root->left, {vert-1, lvl+1}});}
        if(root->right!=NULL){q.push({root->right, {vert+1, lvl+1}});}
    }
    vector<vector<int>>ans;
    for(auto it: m){
        vector<int>v;
        for(auto it1: it.second){
            v.insert(v.end(), it1.second.begin(), it1.second.end());
        }
        ans.push_back(v);
    }
    return ans;
}
;