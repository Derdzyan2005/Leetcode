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
    int rob(TreeNode* root) {
        auto result = helper(root);
        return max(result.first, result.second);
    }
    
private:
    std::pair<int, int> helper(TreeNode* node) {
        if (!node) return {0, 0};
        
        auto left = helper(node->left);
        auto right = helper(node->right);
        
        int robCurrent = node->val + left.second + right.second;
        int skipCurrent = max(left.first, left.second) + max(right.first, right.second);
        
        return {robCurrent, skipCurrent};
    }
};
