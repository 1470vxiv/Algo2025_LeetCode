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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int lastMaxGain = maxGain(root, maxSum); //one side
        return maxSum; //two side
    }
private:
    int maxGain(TreeNode* node, int& maxSum) {
        if (!node) return 0; //base case

        // Recursively get the maximum gain from left and right subtrees
        int leftGain = max(maxGain(node->left, maxSum), 0);
        int rightGain = max(maxGain(node->right, maxSum), 0);

        // Path passing through this node (could be a peak)
        int currentMax = node->val + leftGain + rightGain;

        // Update global max if this is better
        maxSum = max(maxSum, currentMax);

        // Return the best gain including this node and one subtree (cannot take both)
        return node->val + max(leftGain, rightGain);
    }
};
