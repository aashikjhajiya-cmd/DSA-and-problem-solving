class Solution {
public:
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        return 1 + (l > r ? l : r);
    }
    void getLevel(TreeNode* root, int level, vector<int>& res) {
        if (!root) return;
        if (level == 1) res.push_back(root->val);
        else if (level > 1) {
            getLevel(root->left, level - 1, res);
            getLevel(root->right, level - 1, res);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        int h = getHeight(root);
        for (int i = 1; i <= h; i++) {
            vector<int> level;
            getLevel(root, i, level);
            ans.push_back(level);
        }
        return ans;
    }
};
