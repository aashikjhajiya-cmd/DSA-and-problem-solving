class Solution {
public:
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        return 1 + (l > r ? l : r);
    }
    void getLevel(TreeNode* root, int level, bool ltr, vector<int>& res) {
        if (!root) return;
        if (level == 1) res.push_back(root->val);
        else if (level > 1) {
            if (ltr) {
                getLevel(root->left, level - 1, ltr, res);
                getLevel(root->right, level - 1, ltr, res);
            } else {
                getLevel(root->right, level - 1, ltr, res);
                getLevel(root->left, level - 1, ltr, res);
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        int h = getHeight(root);
        bool ltr = true;
        for (int i = 1; i <= h; i++) {
            vector<int> level;
            getLevel(root, i, ltr, level);
            ans.push_back(level);
            ltr = !ltr;
        }
        return ans;
    }
};
