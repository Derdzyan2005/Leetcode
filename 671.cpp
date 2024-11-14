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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        int smallest = root->val;
        int secondSmallest = -1;
        findSecondMin(root, smallest, secondSmallest);
        return secondSmallest;
    }

private:
    void findSecondMin(TreeNode* node, int smallest, int& secondSmallest) {
        if (!node) return;
        if (node->val != smallest) {
            if (secondSmallest == -1 || node->val < secondSmallest) {
                secondSmallest = node->val;
            }
        }
        findSecondMin(node->left, smallest, secondSmallest);
        findSecondMin(node->right, smallest, secondSmallest);
    }
};
