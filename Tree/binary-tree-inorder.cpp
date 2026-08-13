class Solution {
    private:
  void helper(TreeNode* root, vector<int>& res) {
        if (!root) return;
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
        
    }
};
