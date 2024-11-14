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
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        int prevValue = -1;
        inOrderTraversal(root, prevValue, minDiff);
        return minDiff;
    }

private:
    void inOrderTraversal(TreeNode* node, int& prevValue, int& minDiff) {
        if (!node) return;
        
        inOrderTraversal(node->left, prevValue, minDiff);
        
        if (prevValue != -1) {
            minDiff = min(minDiff, node->val - prevValue);
        }
        prevValue = node->val;
        
        inOrderTraversal(node->right, prevValue, minDiff);
    }
};
