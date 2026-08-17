class Solution {
public:
    int findIndex(vector<int>& inorder, int start, int end, int val) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == val) return i;
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preIdx, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        int inIdx = findIndex(inorder, inStart, inEnd, root->val);
        root->left = build(preorder, inorder, preIdx, inStart, inIdx - 1);
        root->right = build(preorder, inorder, preIdx, inIdx + 1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return build(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};
